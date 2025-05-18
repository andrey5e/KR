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

// Количество кораблей
const int SHIPS4COUNT = 1; // 4 - палубник
const int SHIPS3COUNT = 2; // 3 - палубники
const int SHIPS2COUNT = 3; // 2 - палубники
const int SHIPS1COUNT = 4; // 1 - палубники

// Задержка для тестов
const float FOR_TEST_BOT_DELAY = 0.5;

// Задержка для бота
const int REAL_BOT_DELAY = 1;

#endif // DEFINES_H
