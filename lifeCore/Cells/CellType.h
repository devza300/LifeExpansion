#ifndef CELLTYPE_H
#define CELLTYPE_H

/*!
 * \brief The CellType enum - известные типы клеток
 */
enum class CellType : int
{
    /// граница карты, не позволяет оживать или перемещаться клеткам
    EndOfMap,

    /// земля - обычное покрытие, может оживать или преобразовываться в другие типы
    Ground,

    /// стена - не может оживать, препятствует перемещению клеток
    /// может быть разрушена или преобразована в другие типы
    Wall,

    /// жизнь - клетка игрока, может умереть, может быть отобранна другим игроком,
    /// может занимать домашние клетки, рассеивают туман карты,
    /// при удалении на достаточное удаление от Home-клетки теряют управление
    /// (превращаются в Neutral-клетки)
    Live,

    /// домашняя клетка, позволяет производить пыль, необходимую для искуственного
    /// оживления Ground-клеток, увеичивает максимальное количество доступных
    /// для оживления клеток, не может оживать по команде пользователя
    /// предоставляет малый обзор карты
    Home,

    /// живая клетка, не принадлежащая ни одному игроку
    Neutral
};

#endif // CELLTYPE_H
