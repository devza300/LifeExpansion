#ifndef PLAYERINTERFACE_H
#define PLAYERINTERFACE_H

#include <QObject>
#include <QUuid>
#include <QPoint>
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

private:
    QUuid mm_uuid;                  //!< идентификатор игрока

    quint32 mm_maximumCellCount;    //!< максимальное количество клеток, доступных для создания

};

#endif // PLAYERINTERFACE_H
