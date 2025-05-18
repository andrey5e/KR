#include "field.h"

Board::Board() {
    cells.fill(EMPTY, 100); // Инициализация игрового поля 10x10, заполняя все ячейки состоянием EMPTY
}

// Добавление корабля в флот
void Board::addShip(Ship *ship) {
    flot.push_back(ship);
}
