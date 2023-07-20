#ifndef CELL_H
#define CELL_H

#include <QPoint>
#include <QTimer>
#include <QUuid>

class Cell
{
    enum Type
    {
        Regular,
    };

public:
    Cell();

private:
    QPoint mm_point;
    Type mm_type;

    QUuid mm_playerUuid;

};

#endif // CELL_H
