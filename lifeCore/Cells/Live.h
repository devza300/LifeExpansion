#ifndef LIVE_H
#define LIVE_H

#include <QUuid>

#include "AbstractCell.h"

/*!
 * \brief The Live class - живая клетка
 */
class Live : public AbstractCell
{
public:
    /*!
     * \brief Live - конструктор класса
     * \param point - координаты
     * \param uuid - идентификатор игрока
     */
    Live(const QPoint &point, QUuid uuid = {});

    /*!
     * \brief score - очки, начисляемые за соседство с клеткой
     * \param engine - движок карты
     * \return - количество очков
     */
    virtual int score(class MapEngine *engine) override;

    /*!
     * \brief getUuid - идентификатор игрока
     * \return - идентификатор
     */
    QUuid getUuid() const;

    /*!
     * \brief setUuid - изменить идентификатор игрока
     * \param uuid - идентификатор
     */
    void setUuid(const QUuid &uuid);

private:
    QUuid mm_uuid;      //!< идентификатор игрока, которому принадлежит клетка

};

#endif // LIVE_H
