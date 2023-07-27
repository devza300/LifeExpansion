#ifndef CELL_H
#define CELL_H

#include <QPoint>
#include <QUuid>

class Cell
{
    enum Type
    {
        Regular,

        // new cell types will be created in the future
    };

public:
    Cell();

private:
    QPoint mm_point;
    Type mm_type;

    QUuid mm_playerUuid;

};

#endif // CELL_H
