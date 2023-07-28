#include "GameMap.h"

#include "Cells/EndOfMap.h"
#include "Cells/Ground.h"

GameMap::GameMap(int width, int height) :
    mm_rect(0, 0, width, height)
{
    // функция создания границы карты
    auto addEndOfMap = [this] (const QPoint &point)
    {
        EndOfMap *cell = new EndOfMap(point);
        addCell(cell);
    };

    // инициализация границ карты
    for (int x = 0; x < mm_rect.width(); ++x)
    {
        addEndOfMap({x, 0});
        addEndOfMap({x, mm_rect.height() - 1});
    }
    for (int y = 0; y < mm_rect.height(); ++y)
    {
        addEndOfMap({0, y});
        addEndOfMap({mm_rect.width() - 1, y});
    }

    // создание земли
    for (int x = 1; x < mm_rect.width() - 1; ++x)
    {
        for (int y = 1; y < mm_rect.height() - 1; ++y)
        {
            Ground *cell = new Ground({x, y});
            addCell(cell);
        }
    }
}

GameMap::~GameMap()
{
    deleteCells(mm_cells.values());
}

QRect GameMap::getRect() const
{
    return mm_rect;
}

QList<AbstractCell *> GameMap::getCells() const
{
    return mm_cells.values();
}

AbstractCell *GameMap::getCell(const QPoint &point) const
{
    return mm_cells.value(point, nullptr);
}

QList<AbstractCell *> GameMap::cellsAround(AbstractCell *cell) const
{
    QPoint point = cell->getPoint();

    // список соседних координат
    QList<QPoint> nearPoints = {
        {1, 0},
        {1, 1},
        {0, 1},
        {-1, 1},
        {-1, 0},
        {-1, -1},
        {0, -1},
        {1, -1}
    };

    // поиск клеток в соседних координатах
    QList<AbstractCell *> result;
    foreach (auto near, nearPoints)
    {
        auto nearCell = getCell(point + near);

        if (!nearCell)
            continue;

        result += nearCell;
    }

    return result;
}

void GameMap::addCell(AbstractCell *cell)
{
    auto point = cell->getPoint();

    // проверка: помещатся клетка на карту?
    if (!mm_rect.contains(point))
        return;

    // проверка: клетка уже есть на карте?
    if (mm_cells.contains(point) && getCell(point)->getType() == CellType::Ground)
        deleteCell(getCell(point));
    else
    {
        delete cell;
        return;
    }

    mm_cells.insert(cell->getPoint(), cell);
}

void GameMap::addCells(QList<AbstractCell *> cells)
{
    foreach (auto cell, cells)
        addCell(cell);
}

void GameMap::deleteCell(AbstractCell *cell)
{
    auto point = cell->getPoint();

    // проверка: клетка есть на карте?
    if (mm_cells.contains(point))
        mm_cells.remove(point);

    delete cell;
}

void GameMap::deleteCells(QList<AbstractCell *> cells)
{
    foreach (auto cell, cells)
        addCell(cell);
}
