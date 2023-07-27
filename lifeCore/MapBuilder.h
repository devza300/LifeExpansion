#ifndef MAPBUILDER_H
#define MAPBUILDER_H

#include "GameMap.h"

class MapBuilder : public GameMap
{
public:
    MapBuilder(const GameMap &map);

    GameMap getMap() const;

    void saveToFile(const QString &file);

    void setMapRect(const QRect &rect);

    void addGround(const Ground &ground);
    void addGround(const QList<Ground> &groundList);

    void addHomePoint(const QPoint &point);
    void addHomePoint(const QList<QPoint> &pointList);

};

#endif // MAPBUILDER_H
