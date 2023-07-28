#include "Ground.h"

Ground::Ground(const QPoint &point) :
    AbstractCell(point)
{
    setType(CellType::Ground);
}

int Ground::score(MapEngine *engine)
{
    Q_UNUSED(engine)

    return 0;
}
