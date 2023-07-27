#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QList>
#include <QRect>

#include "Ground.h"

class GameMap
{
public:
    GameMap(const QRect &rect = QRect(),
            const QList<Ground> &ground = {},
            const QList<QPoint> &homePoints = {});

    GameMap(const QString &path);

    QPoint getMapRect() const;
    QList<Ground> getGround() const;
    QList<QPoint> getHomePoints() const;

private:
    QRect mm_mapRect;               //!< размер карты

    QList<Ground> mm_ground;        //!<
    QList<QPoint> mm_homePoints;

};

#endif // GAMEMAP_H
