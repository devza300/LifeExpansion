#include "AbstractCell.h"

AbstractCell::AbstractCell(const QPoint &point) :
    mm_point(point)
{

}

QPoint AbstractCell::getPoint() const
{
    return mm_point;
}

CellType AbstractCell::getType() const
{
    return mm_type;
}

void AbstractCell::setType(const CellType &type)
{
    mm_type = type;
}
