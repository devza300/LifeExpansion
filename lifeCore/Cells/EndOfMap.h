#ifndef ENDOFMAP_H
#define ENDOFMAP_H

#include "AbstractCell.h"

/*!
 * \brief The EndOfMap class - конец карты
 */
class EndOfMap : public AbstractCell
{
public:
    /*!
     * \brief EndOfMap - конструктор класса
     * \param point - координаты
     */
    EndOfMap(const QPoint &point);

    /*!
     * \brief score - очки, начисляемые за соседство с клеткой
     * \param engine - движок карты
     * \return - количество очков
     */
    virtual int score(class MapEngine *engine) override;

};

#endif // ENDOFMAP_H
