#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

#include <QRandomGenerator>
#include <QHash>
#include <QTimer>

#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void generateInitialState(int count);

private slots:
    void timeoutEpoch();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

//public slots:
//    void mousePressEvent(QMouseEvent *e);

//    void mouseMoveEvent(QMouseEvent *e);

protected:
    bool eventFilter(QObject *obj, QEvent *event);

private:
    void riseUnit(QPoint point);
    void killUnit(QPoint point);

private:
    Ui::MainWindow *ui;

    QRandomGenerator mm_generator;
    QTimer mm_timerEpoch;
    QGraphicsScene mm_scene;
    QHash<QPoint, QGraphicsRectItem*> mm_unitHash;

    QGraphicsRectItem *ptr_unitCursor;
    bool mm_pressed;

};

#endif // MAINWINDOW_H
