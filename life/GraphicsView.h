#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsView(QGraphicsScene *scene = nullptr, QWidget *parent = nullptr);

    bool viewportEvent(QEvent *event) override;

private:
    qreal totalScaleFactor = 1;

};

#endif // GRAPHICSVIEW_H
