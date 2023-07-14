#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDateTime>
#include <QDebug>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>

inline uint qHash(const QPoint &key)
{
    return qHash(QPair<int, int>(key.x(), key.y()));
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mm_generator(QDateTime::currentMSecsSinceEpoch()),
    mm_timerEpoch(this),
    mm_scene(this),
    mm_pressed(false)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(&mm_scene);
    mm_scene.setBackgroundBrush(QBrush(Qt::black));

    connect(&mm_timerEpoch, &QTimer::timeout,
            this, &MainWindow::timeoutEpoch);

    mm_scene.installEventFilter(this);
    ui->graphicsView->setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateInitialState(int count)
{
    for (int i = 0; i < count; ++i)
    {
        auto genPoint = [this]()
        {
            int x = mm_generator.bounded(0, 10);
            int y = mm_generator.bounded(0, 10);

            return QPoint(x, y);
        };

        QPoint point = genPoint();



        riseUnit(point);
    }
}

void MainWindow::timeoutEpoch()
{
    auto keys = mm_unitHash.keys();

    // initialize kill list
    QList<QPoint> checkToRise;
    QList<QPoint> killList;
    foreach (auto point, keys)
    {
        auto analyze = [point, keys](int &alive, QList<QPoint> &checkToRise, int x, int y)
        {
            QPoint seek = point + QPoint(x, y);

            if (keys.contains(seek))
                alive++;
            else
                checkToRise.append(seek);
        };

        int count_alive = 0;
        analyze(count_alive, checkToRise, 1, 0);
        analyze(count_alive, checkToRise, 1, 1);
        analyze(count_alive, checkToRise, 0, 1);
        analyze(count_alive, checkToRise, -1, 1);
        analyze(count_alive, checkToRise, -1, 0);
        analyze(count_alive, checkToRise, -1, -1);
        analyze(count_alive, checkToRise, 0, -1);
        analyze(count_alive, checkToRise, 1, -1);


        if (count_alive == 2 || count_alive == 3)
            continue;

        killList.append(point);
    }


    // rise
    foreach (auto point, checkToRise)
    {
        if (checkToRise.count(point) != 3)
        {
            checkToRise.removeAll(point);
            continue;
        }

        riseUnit(point);

        checkToRise.removeAll(point);
    }

    // kill
    foreach (auto point, killList)
        killUnit(point);
}

void MainWindow::on_pushButton_clicked()
{
    mm_timerEpoch.isActive() ? mm_timerEpoch.stop() : mm_timerEpoch.start(ui->spinBox->value());
}

void MainWindow::on_pushButton_2_clicked()
{
    foreach (auto point, mm_unitHash.keys())
        killUnit(point);
}

void MainWindow::riseUnit(QPoint point)
{
    if (mm_unitHash.contains(point))
        return;

    QGraphicsRectItem *unit = new QGraphicsRectItem(point.x() * 10, point.y() * 10, 8, 8);
    QPen outlinePen(Qt::white);
    outlinePen.setWidth(1);
    unit->setPen(outlinePen);
    unit->setBrush(QBrush(Qt::white));

    mm_scene.addItem(unit);
    mm_unitHash.insert(point, unit);
}

void MainWindow::killUnit(QPoint point)
{
    auto unit = mm_unitHash.value(point);
    mm_unitHash.remove(point);
    mm_scene.removeItem(unit);
    delete unit;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{

    switch (event->type())
    {
    case QEvent::Enter:
        QApplication::setOverrideCursor(QCursor(Qt::BlankCursor));
        break;

    case QEvent::Leave:
        QApplication::setOverrideCursor(QCursor(Qt::ArrowCursor));
        break;

    case QEvent::GraphicsSceneMousePress:
    {
        mm_pressed = true;

        QPointF pos = ui->graphicsView->mapToScene(ui->graphicsView->viewport()->mapFromGlobal(QCursor::pos()));
        QPoint point(pos.x() / 10, pos.y() / 10);
        riseUnit(point);

        break;
    }

    case QEvent::GraphicsSceneMouseRelease:
        mm_pressed = false;
        break;


    case QEvent::GraphicsSceneMouseMove:
    {
        if (mm_scene.items().contains(ptr_unitCursor))
            mm_scene.removeItem(ptr_unitCursor);

        QPointF pos = ui->graphicsView->mapToScene(ui->graphicsView->viewport()->mapFromGlobal(QCursor::pos()));
        QPoint point(pos.x() / 10, pos.y() / 10);

        QPen outlinePen(Qt::green);
        outlinePen.setWidth(1);

        ptr_unitCursor = mm_scene.addRect(point.x() * 10, point.y() * 10, 8, 8, outlinePen, QBrush(Qt::green));

        if (mm_pressed)
            riseUnit(point);

        break;
    }

    default:
        break;
    }

    event->accept();

    return QObject::eventFilter(obj, event);
}

