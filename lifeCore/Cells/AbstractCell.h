#ifndef ABSTRACTCELL_H
#define ABSTRACTCELL_H

#include <QPoint>

#include "CellType.h"

/*!
 * \brief The AbstractCell class - базовое представление клетки карты
 */
class AbstractCell
{
public:
    /*!
     * \brief AbstractCell - конструктор класса
     * \param point - координаты
     */
    AbstractCell(const QPoint &point);

    /*!
     * \brief ~AbstractCell - деструктор для корректного удаления по указателю на объект абстрактного класса
     */
    virtual ~AbstractCell() = default;

    /*!
     * \brief score - очки, начисляемые за соседство с клеткой
     * \param engine - движок карты
     * \return - количество очков
     */
    virtual int score(class MapEngine *engine) = 0;

    /*!
     * \brief getPoint - координаты клетки
     * \return - x, y
     */
    QPoint getPoint() const;

    /*!
     * \brief getType - тип клетки
     * \return - тип
     */
    CellType getType() const;

protected:
    /*!
     * \brief setType - задать тип клетки
     * \param type - тип клетки
     */
    void setType(const CellType &type);

private:
    QPoint mm_point;    //!< координаты клетки
    CellType mm_type;   //!< тип клетки

};

#endif // ABSTRACTCELL_H
