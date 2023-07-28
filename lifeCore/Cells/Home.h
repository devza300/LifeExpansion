#ifndef HOME_H
#define HOME_H

#include "Live.h"

/*!
 * \brief The Home class - домашняя клеткадомашняя клетка
 */
class Home : public Live
{
public:
    Home(const QPoint &point, int alive, int powder, int vision, QUuid uuid = {});

    /*!
     * \brief alive - количество клеток, прелоставляемых для создания
     * \return - количество клеток
     */
    int alive() const;

    /*!
     * \brief powder - количество пыли, начисляемой владельцу
     * \return - количество пыли
     */
    int powder() const;

    /*!
     * \brief vision - радиус обзора вокруг клетки
     * \return - радиус в количестве клеток
     */
    int vision() const;

private:
    int mm_alive;       //!< количество клеток, прелоставляемых для создания
    int mm_powder;      //!< количество пыли, начисляемой владельцу
    int mm_vision;      //!< радиус обзора вокруг клетки

};

#endif // HOME_H
