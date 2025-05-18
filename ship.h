#ifndef SHIP_H
#define SHIP_H

#include <QDebug>
#include <QPoint>

class Ship {
protected:
    int weight; // Вес (размер) корабля
    QPoint coords; // Координаты расположения корабля на игровом поле
    int shipHealth; // Здоровье корабля (количество оставшихся палуб)
    bool orientation; // Ориентация корабля (горизонтальная или вертикальная)
public:
    int getWeight(); // Получение веса корабля
    void setCoords(QPoint point); // Установка координат корабля
    int getHealth(); // Получение текущего здоровья корабля
    QPoint getCoords(); // Получение координат корабля
    void shipDamage(); // Нанесения урона кораблю
};

// Однопалубный корабль
class OnePartShip : public Ship {
public:
    OnePartShip() {
        weight = 1; // Вес корабля
        shipHealth = weight; // Здоровье = вес
    }
};

// Двухпалубный корабль
class TwoPartShip : public Ship {
public:
    TwoPartShip() {
        weight = 2; // Вес корабля
        shipHealth = weight; // Здоровье = вес
    }
};

// Трёхпалубный корабль
class ThreePartShip : public Ship {
public:
    ThreePartShip() {
        weight = 3; // Вес корабля
        shipHealth = weight; // Здоровье = вес
    }
};

// Четырёхпалубный корабль
class FourPartShip : public Ship {
public:
    FourPartShip() {
        weight = 4; // Вес корабля
        shipHealth = weight; // Здоровье = вес
    }
};

#endif // SHIP_H
