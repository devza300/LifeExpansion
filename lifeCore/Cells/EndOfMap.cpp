#include "EndOfMap.h"

EndOfMap::EndOfMap(const QPoint &point) :
    AbstractCell(point)
{
    setType(CellType::EndOfMap);
}

int EndOfMap::score(MapEngine *engine)
{
    Q_UNUSED(engine)

    // NOTE наверняка уничтожаем все приблизившиеся клетки
    return 100;
}
