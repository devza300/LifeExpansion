#include "MapEngine.h"

#include <QHash>

#include "Cells/Ground.h"
#include "Cells/Home.h"

MapEngine::MapEngine(QObject *parent, int width, int height, int speed) :
    QObject(parent),
    GameMap(width, height),
    mm_timer(this)
{
    mm_timer.setInterval(10000 / speed);

    connect(&mm_timer, &QTimer::timeout,
            this, &MapEngine::onTimeout);
}

void MapEngine::changeSpeed(int speed)
{
    mm_timer.setInterval(10000 / speed);
}

void MapEngine::play()
{
    mm_timer.start();
}

void MapEngine::pause()
{
    mm_timer.stop();
}

void MapEngine::calcPlayerPowderOnEpoch()
{
    auto cells = getCells();

    QHash<QUuid, int> playerPowder;
    foreach (auto cell, cells)
    {
        if (cell->getType() != CellType::Home)
            continue;

        auto home = static_cast<Home*>(cell);

        int score = playerPowder.value(home->getUuid()) + home->score(this);
        playerPowder.insert(home->getUuid(), score);
    }

    auto uuidList = playerPowder.keys();
    for (auto uuid : uuidList)
    {
        // незанятые доманшие клетки
        if (uuid == QUuid())
            continue;

        emit appendPlayerPowder(uuid, playerPowder.value(uuid));
    }
}

void MapEngine::onTimeout()
{
    // вычисление количества пыли игроков
    calcPlayerPowderOnEpoch();

    auto cells = getCells();

    QList<AbstractCell *> checkList;
    foreach (auto cell, cells)
    {
        if (cell->getType() != CellType::Live)
            continue;

        // получение живых клеток
        checkList.append(cell);

        // получение соседних клеток земли
        auto nearCells = cellsAround(cell);
        foreach (auto near, nearCells)
        {
            if (near->getType() != CellType::Ground)
                continue;

            if (checkList.contains(near))
                continue;

            checkList.append(near);
        }
    }

    for (auto cell : checkList)
    {
        int score = cell->score(this);

        if (score == 2)
            continue;

        // что-то можно ожилять
        if (score == 3)
        {
            switch (cell->getType())
            {
            case CellType::Home:
                // TODO занять домашнюю клетку
                break;

            case CellType::Ground:
                // TODO воскресить (и передать нужному игроку)
                break;

            default:
                break;
            }
        }

        // удалять можно только живые клетки
        if (cell->getType() != CellType::Live)
            continue;

        deleteCell(cell);
    }
}
