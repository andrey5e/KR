#include "player.h"

Player::Player() {
    board = new Board(); // Формирование игрового поля
}

Player::~Player() {
    delete board; // Освобождение памяти (удаление игрового поля)
}

// Создание флота
void Player::createFlot() {
    for (int i {0}; i < SHIPS4COUNT; i++) {
        board->addShip(createShip(4));
    }
    for (int i {0}; i < SHIPS3COUNT; i++) {
        board->addShip(createShip(3));
    }
    for (int i {0}; i < SHIPS2COUNT; i++) {
        board->addShip(createShip(2));
    }
    for (int i {0}; i < SHIPS1COUNT; i++) {
        board->addShip(createShip(1));
    }
}

// Получение игрового поля игрока
Board *Player::getBoard() {
    return board;
}

// Выстрел в заданную точку
QPoint Player::performShot(QPoint point) {
    return shotS->shot(point);
}

// Создание корабля
Ship* HumanPlayer::createShip(int w) {
    if (w == 1) {
        return new OnePartShip();
    } else if (w == 2) {
        return new TwoPartShip();
    } else if (w == 3) {
        return new ThreePartShip();
    } else if (w == 4) {
        return new FourPartShip();
    } else {
        qDebug() << "Некорректный вес корабля.";
        return nullptr;
    }
}

// Создание вражеского корабля
Ship* AIPlayer::createShip(int w) {
    if (w == 1) {
        return new OnePartShip();
    } else if (w == 2) {
        return new TwoPartShip();
    } else if (w == 3) {
        return new ThreePartShip();
    } else if (w == 4) {
        return new FourPartShip();
    } else {
        qDebug() << "Некорректный вес корабля.";
        return nullptr;
    }
}
