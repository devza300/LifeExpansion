#ifndef CELLLIVE_H
#define CELLLIVE_H

#include <QPoint>
#include <QTimer>
#include <QUuid>

class CellLive
{
    enum LiveType
    {

    };

public:
    CellLive();

private:
    QPoint mm_point;
    LiveType mm_type;

    QUuid mm_playerUuid;

};

#endif // CELLLIVE_H
