#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QRect>
#include <QHash>

#include "Cells/AbstractCell.h"

/*!
 * \brief The GameMap class - карта игры
 */
class GameMap
{
public:
    /*!
     * \brief GameMap - конструктор класса
     * \param width - ширина
     * \param height - высота
     */
    GameMap(int width, int height);

    /// удаление клеток
    ~GameMap();

    /*!
     * \brief getRect - пространство карты
     * \return - прямоугольник
     */
    QRect getRect() const;

    /*!
     * \brief getCells - все клетки на карте
     * \return - список клеток
     */
    QList<AbstractCell *> getCells() const;

    /*!
     * \brief getCell - клетка по заданным координатам
     * \param point - координаты
     * \return - клетка
     */
    AbstractCell *getCell(const QPoint &point) const;

    /*!
     * \brief cellsAround - список клеток вокруг заданной клетки
     * \param cell - клетка, относительно которой производится поиск
     * \return - список клеток
     */
    QList<AbstractCell *> cellsAround(AbstractCell *cell) const;

    /*!
     * \brief addCell - добавить клетку
     * \param cell - клетка
     */
    void addCell(AbstractCell *cell);

    /*!
     * \brief addCells - добавить клетки
     * \param cells - клетки
     */
    void addCells(QList<AbstractCell *> cells);

    /*!
     * \brief deleteCell - удалить клетку
     * \param cell - клетка
     */
    void deleteCell(AbstractCell *cell);

    /*!
     * \brief deleteCells - удалить клетки
     * \param cells - клетки
     */
    void deleteCells(QList<AbstractCell *> cells);

private:
    QRect mm_rect;                              //!< прямоугольник карты
    QHash<QPoint, AbstractCell *> mm_cells;     //!< клетки

};

#endif // GAMEMAP_H
