#ifndef DEMOMAPS_H
#define DEMOMAPS_H

#include "GameMap.h"

static const GameMap LittleMap = {
    QRect(0, 0, 128, 128),
    {
        Ground(Ground::Wall, 10, 10),
        Ground(Ground::Wall, 11, 11),
        Ground(Ground::Wall, 12, 12),
        Ground(Ground::Wall, 13, 13)
    },
    {
        QPoint(15, 15),
        QPoint(25, 25),
    }
};

#endif // DEMOMAPS_H
