#ifndef DEFINES_H
#define DEFINES_H

// Размеры игрового поля для игрока
const int MYFIELD_X = 41; // Ширина
const int MYFIELD_Y = 41; // Высота

// Половинные размеры игрового поля для центрования
const int MYFIELD_HALF_X = 148;
const int MYFIELD_HALF_Y = 148;

// Размеры игрового поля для противника
const int ENEMYFIELD_X = 323; // Ширина
const int ENEMYFIELD_Y = 42;  // Высота

// Половинные размеры игрового поля противника для центрования
const int ENEMYFIELD_HALF_X = 430;
const int ENEMYFIELD_HALF_Y = 148;

// Общие размеры игрового поля
const int FIELD_WIDTH = 216; // Ширина
const int FIELD_HEIGHT = 217; // Высота

// Размер ячейки на игровом поле (ширина / 10)
const int CELL_SIZE = FIELD_WIDTH / 10;

#endif // DEFINES_H
