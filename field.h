#ifndef FIELD_H
#define FIELD_H

#include <QVector>
#include "ship.h"

enum Cell {
    EMPTY,
    DOT,
    SHIP,
    DEAD,
    DAMAGED
};

class Board {
public:
    Board();
    void addShip(Ship* ship); // Добавление корабля в флот
    void setCellState(QPoint point, Cell state); // Установка состояния ячейки на игровом поле
    Cell getCellState(QPoint point); // Получение состояния ячейки на игровом поле
    void printBoardStates(); // Вывод состояния игрового поля в виде матрицы
    QVector<Cell> getCells(); // Получение всех ячеек игрового поля
    QVector<Ship *> getFlot(); // Получения флота (списка кораблей)
    void prettyPrintFlot(); // Вывод информации о кораблях
    void clear(); // Очистка игрового поля, устанавливая все ячейки в состояние EMPTY
    Ship *getShipByCell(QPoint point); // Получение корабля по координатам ячейки
private:
    QVector<Cell> cells;
    QVector<Ship*> flot;
};

#endif // FIELD_H
