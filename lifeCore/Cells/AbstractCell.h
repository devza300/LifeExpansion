#ifndef ABSTRACTCELL_H
#define ABSTRACTCELL_H

#include <QPoint>
#include <QUuid>

class AbstractCell
{
public:
    AbstractCell();

    virtual void operator()() = 0;

private:
    QPoint mm_point;
    QUuid mm_uuid;

};

#endif // ABSTRACTCELL_H
