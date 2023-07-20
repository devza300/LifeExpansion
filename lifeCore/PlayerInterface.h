#ifndef PLAYERINTERFACE_H
#define PLAYERINTERFACE_H

#include <QObject>
#include <QUuid>

#include "Ground.h"
#include "Cell.h"
#include "LifeCore.h"

class PlayerInterface
{
public:
    PlayerInterface(LifeCore *core, QUuid uuid);

    quint32 maxLiveCellCount() const;

    quint32 currentLiveCellCount() const;

    quint32 availaleLiveCellCount() const;

    QList<QPoint> mapVisibility() const;

    QList<QPoint> mapSmoke() const;

//    void insertCells(const QList<QPoint> &coordinates);

    void insertLiveCells(const QList<Cell> &cells);
    
    void modifyGround(const QList<Ground> &cells);

private:
    QUuid mm_uuid;
    
    LifeCore *ptr_core;

};

#endif // PLAYERINTERFACE_H
