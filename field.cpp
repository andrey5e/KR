#include "field.h"

Board::Board() {
    cells.fill(EMPTY, 100); // Инициализация игрового поля 10x10, заполняя все ячейки состоянием EMPTY
}

// Добавление корабля в флот
void Board::addShip(Ship *ship) {
    flot.push_back(ship);
}

// Установка состояния ячейки на игровом поле
void Board::setCellState(QPoint point, Cell state) {
    if (point.x() < 10 && point.x() >= 0 && point.y() < 10 && point.y() >= 0)
        cells[point.x() + 10 * point.y()] = state;
}

// Получение состояния ячейки на игровом поле
Cell Board::getCellState(QPoint point) {
    if (point.x() > 9 || point.y() > 9 || point.x() < 0 || point.y() < 0) {
        return Cell::EMPTY;
    }
    return cells[point.x() + 10 * point.y()];
}

// Вывод состояния игрового поля в виде матрицы
void Board::printBoardStates() {
    for (int i = 0; i < 10; i++) {
        QString str = "";
        for (int j {0}; j < 10; j++) {
            str += QString::number(cells[i * 10 + j]) + " ";
        }
        qDebug() << str;
    }
    qDebug() << "\n";
}
