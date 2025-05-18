#include "shot.h"

// Ручной выстрел
QPoint ManualShotStrategy::shot(QPoint point) {
    return point;
}

// Случайный выстрел
QPoint FullRandomShotStrategy::shot(QPoint point) {
    srand(time(NULL));
    return QPoint(rand() % 10, rand() % 10);
}
