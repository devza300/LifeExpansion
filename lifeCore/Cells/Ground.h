#ifndef GROUND_H

#include "AbstractCell.h"

/*!
 * \brief The Ground class - земля
 */
class Ground : public AbstractCell
{
public:
    /*!
     * \brief Ground - конструктор класса
     * \param point - координаты
     */
    Ground(const QPoint &point);

    /*!
     * \brief score - очки, начисляемые за соседство с клеткой
     * \param engine - движок карты
     * \return - количество очков
     */
    virtual int score(class MapEngine *engine) override;

};

#endif // GROUND_H
