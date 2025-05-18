#include "ship.h"

// Получение веса корабля
int Ship::getWeight() {
    return weight;
}

// Установка координат корабля
void Ship::setCoords(QPoint point) {
    coords = point;
}

// Получение текущего здоровья корабля
int Ship::getHealth() {
    return shipHealth;
}

// Получение координат корабля
QPoint Ship::getCoords() {
    return coords;
}

// Нанесение урона кораблю
void Ship::shipDamage() {
    shipHealth--;
}
