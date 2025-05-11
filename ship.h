#ifndef SHIP_H
#define SHIP_H

#include <QDebug>
#include <QPoint>

class Ship {
protected:
    int weight;
    QPoint coords;
    int shipHealth;
    bool orientation;
public:
    Ship() {};
    int getWeight();
    void setCoords(QPoint point);
    int getHealth();
    QPoint getCoords();
    void shipDamage();
};

class OnePartShip : public Ship {
public:
    OnePartShip() {
        weight = 1;
        shipHealth = weight;
    }
};

class TwoPartShip : public Ship {
public:
    TwoPartShip() {
        weight = 2;

        shipHealth = weight;
    }
};

class ThreePartShip : public Ship {
public:
    ThreePartShip() {
        weight = 3;

        shipHealth = weight;
    }
};

#endif // SHIP_H
