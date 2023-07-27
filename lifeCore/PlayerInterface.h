#ifndef PLAYERINTERFACE_H
#define PLAYERINTERFACE_H

#include <QObject>
#include <QUuid>

#include "Cell.h"
#include "Ground.h"
#include "LifeCore.h"

class PlayerInterface : public QObject
{
    Q_OBJECT

public:
    PlayerInterface(LifeCore *core, QUuid uuid);

    QUuid getUuid() const;

    quint32 maxLiveCellCount() const;

    QList<QPoint> mapVision() const;

public slots:
    void reloadArea(const QList<QPoint> &points);

signals:
    void visionChanged(const QList<QPoint> &points);

    void cellsRise(const QList<Cell> &cells);

    void cellsDie(const QList<Cell> &cells);

    void maxCellCountChenged(quint32 maximum);

    void groundData(const QList<Ground> &data);

private:
    QUuid mm_uuid;                  //!< идентификатор игрока

    QList<Cell> mm_cells;           //!< доступные игроку клетки (видимые)
    QList<Ground> mm_ground;        //!< изученная игроком почва

    quint32 mm_maximumCellCount;    //!< максимальное количество клеток, доступных для создания

};

#endif // PLAYERINTERFACE_H
