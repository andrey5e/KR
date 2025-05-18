#include "field.h"

Board::Board() {
    cells.fill(EMPTY, 100); // Инициализация игрового поля 10x10 (все ячейки состояния EMPTY)
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

// Получение всех ячеек игрового поля
QVector<Cell> Board::getCells() {
    return cells;
}

// Получения флота (списка кораблей)
QVector<Ship *> Board::getFlot() {
    return flot;
}

// Вывод информации о кораблях
void Board::prettyPrintFlot() {
    for (Ship* ship : flot) {
        qDebug() << "w: " << ship->getWeight() << ", " << ship->getCoords();
    }
}

// Очистка игрового поля, устанавливая все ячейки в состояние EMPTY
void Board::clear() {
    for (Cell &cell : cells) {
        cell = Cell::EMPTY;
    }
}

// Получение корабля по координатам ячейки
Ship *Board::getShipByCell(QPoint point) {
    if (getCellState(point) != Cell::SHIP) {
        qDebug() << "В функцию getShipByCell передана клетка без корабля.";
        return nullptr;
    }
    for (Ship* ship : flot) {
        if (ship->getCoords() == point)
            return ship;
    }
    if (getCellState(QPoint(point.x() - 1, point.y())) == Cell::SHIP ||
        getCellState(QPoint(point.x() - 1, point.y())) == Cell::DAMAGED) {
        while (true) {
            point = QPoint(point.x() - 1, point.y());
            for (Ship* ship : flot) {
                if (ship->getCoords() == point)
                    return ship;
            }
        }
    } else {
        while (true) {
            point = QPoint(point.x(), point.y() - 1);
            for (Ship* ship : flot) {
                if (ship->getCoords() == point)
                    return ship;
            }
        }
    }
    qDebug() << "Корабль не найден.";
    return nullptr;
}
