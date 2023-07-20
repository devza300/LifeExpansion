#ifndef LIFECORE_H
#define LIFECORE_H

#include <QObject>

#include "GameMap.h"

class PlayerInterface;

class LifeCore : public QObject
{
    Q_OBJECT

public:
    LifeCore(QObject *parent, const GameMap &map);

    /// @todo

    PlayerInterface *createPlayer(const QPoint &homePoint);

private:

};

#endif // LIFECORE_H
