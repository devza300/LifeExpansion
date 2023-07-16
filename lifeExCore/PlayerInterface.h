#ifndef PLAYERINTERFACE_H
#define PLAYERINTERFACE_H

#include <QObject>
#include <QUuid>

#include "CellGround.h"
#include "CellLive.h"
#include "LifeExCore.h"

class PlayerInterface
{
public:
    PlayerInterface(LifeExCore *core, QUuid uuid);

    quint32 maxLiveCellCount() const;

    quint32 currentLiveCellCount() const;

    quint32 availaleLiveCellCount() const;

    QList<QPoint> mapVisibility() const;

    QList<QPoint> mapSmoke() const;

//    void insertCells(const QList<QPoint> &coordinates);

    void insertLiveCells(const QList<CellLive> &cells);

    void modifyGround(const QList<CellGround> &cells);

private:
    QUuid mm_uuid;

    LifeExCore *ptr_core;

};

#endif // PLAYERINTERFACE_H
