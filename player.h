#ifndef PLAYER_H
#define PLAYER_H

#include "field.h"
#include "defines.h"
#include "shot.h"

class Player {
public:
    Player();
    virtual ~Player();
    virtual Ship* createShip(int w) = 0;
    void createFlot(); // Создание флота
    Board *getBoard(); // Получение игрового поля игрока
    QPoint performShot(QPoint point = QPoint(-1, -1)); // Выстрел в заданную точку
protected:
    Board* board;
    ShotsStrategy* shotS;
};

class HumanPlayer : public Player {
public:
    HumanPlayer() {
        shotS = new ManualShotStrategy();
    };
    Ship* createShip(int w) override; // Создание корабля
};

class AIPlayer : public Player {
public:
    AIPlayer() {
        shotS = new FullRandomShotStrategy();
    };
    Ship* createShip(int w) override; // Создание вражеского корабля
};

#endif // PLAYER_H
