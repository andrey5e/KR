#include "player.h"

Player::Player() {
    board = new Board();
}
Player::~Player() {}

void Player::createFlot() {
    
    // 4 - палубники
    for (int i {0}; i < SHIPS4COUNT; i++) {
        board->addShip(createShip(4));
    }

    // 3 - палубники
    for (int i {0}; i < SHIPS3COUNT; i++) {
        board->addShip(createShip(3));
    }

    // 2 - палубники
    for (int i {0}; i < SHIPS2COUNT; i++) {
        board->addShip(createShip(2));
    }

    // 1 - палубники
    for (int i {0}; i < SHIPS1COUNT; i++) {
        board->addShip(createShip(1));
    }
}

Board *Player::getBoard() {
    return board;
}

QPoint Player::performShot(QPoint point) {
    return shotS->shot(point);
}

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
        qDebug() << "Введён некорректный вес корабля";
        return nullptr;
    }
}

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
        qDebug() << "Введён некорректный вес корабля";
        return nullptr;
    }
}
