#ifndef MAPENGINE_H
#define MAPENGINE_H

#include <QObject>
#include <QTimer>

#include "GameMap.h"

/*!
 * \brief The MapEngine class - движок карты, вычисляет состояние клеток для эпох
 */
class MapEngine : public QObject, public GameMap
{
    Q_OBJECT

public:
    /*!
     * \brief MapEngine - конструктор класса
     * \param parent - объект-родитель
     * \param width - ширина
     * \param height - высота
     * \param speed - скорость игры (1 - 100)
     */
    MapEngine(QObject *parent, int width, int height, int speed);

    /*!
     * \brief changeSpeed - изменить скорость игры
     * \param speed - скорость (1 - 100)
     */
    void changeSpeed(int speed);

    /*!
     * \brief play - запуск
     */
    void play();

    /*!
     * \brief pause - пауза
     */
    void pause();

signals:
    /*!
     * \brief appendPlayerPowder - увеличилось количество пыли для игрока
     * \param uuid - идентификатор
     * \param append - пыль
     */
    void appendPlayerPowder(const QUuid &uuid, int append);

private:
    /*!
     * \brief calcPlayerPowderOnEpoch - вычисление прироста пыли
     */
    void calcPlayerPowderOnEpoch();

private slots:
    /*!
     * \brief onTimeout - эпоха карты
     */
    void onTimeout();

private:
    QTimer mm_timer;    //!< игровой таймер

};

#endif // MAPENGINE_H
