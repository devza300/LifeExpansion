#include "Home.h"

Home::Home(const QPoint &point, int alive, int powder, int vision, QUuid uuid) :
    Live(point, uuid),
    mm_alive(alive),
    mm_powder(powder),
    mm_vision(vision)
{
    setType(CellType::Home);
}

int Home::alive() const
{
    return mm_alive;
}

int Home::powder() const
{
    return mm_powder;
}

int Home::vision() const
{
    return mm_vision;
}
