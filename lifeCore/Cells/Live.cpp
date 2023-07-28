#include "Live.h"
#include "CellType.h"

Live::Live(const QPoint &point, QUuid uuid) :
    AbstractCell(point),
    mm_uuid(uuid)
{
    setType(CellType::Live);
}

int Live::score(MapEngine *engine)
{
    // TODO реализовать динамическое вычисление очков
    Q_UNUSED(engine)

    return 1;
}

QUuid Live::getUuid() const
{
    return mm_uuid;
}

void Live::setUuid(const QUuid &uuid)
{
    mm_uuid = uuid;
}
