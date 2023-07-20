#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QList>
#include <QRect>

#include "Ground.h"

class GameMap
{
public:
    GameMap(const QRect &rect = QRect(),
            const QList<Ground> &groundList = {},
            const QList<QPoint> &homePoints = {});

    QPoint getMapRect() const;

    void setMapRect(const QRect &rect);


    QList<Ground> getGround() const;

    void addGround(const Ground &ground);
    void addGround(const QList<Ground> &groundList);


    QList<QPoint> getHomePoints() const;

    void addHomePoint(const QPoint &point);
    void addHomePoint(const QList<QPoint> &pointList);

private:
    QRect mm_mapRect;
    QList<Ground> mm_groundList;
    QList<QPoint> mm_homePoints;

};

#endif // GAMEMAP_H
