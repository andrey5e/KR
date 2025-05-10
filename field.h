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

#endif // FIELD_H
