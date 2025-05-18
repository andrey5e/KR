#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "player.h"
#include <unistd.h>
#include <QLabel>

enum GameState {
    SHIPS_PLACING,
    PLAYER_TURN,
    ENEMY_TURN,
    GAMEOVER
};

class GameController {
public:
    GameController();
    ~GameController();
    GameState getGameState(); // Получение текущего состояния игры
    void createFlots(); // Создание флотов для игрока и бота
    int getPlayerShipCellsCount(); // Получение количества ячеек с кораблями у игрока
    int getBotShipCellsCount(); // Получение количества ячеек с кораблями у бота
    bool isPlayerEmptyCell(QPoint point); // Проверка, является ли ячейка пустой у игрока
    bool isBotEmptyCell(QPoint point); // Проверка, является ли ячейка пустой у бота
    void setPlayerCellState(QPoint point, int stateNum); // Установка состояния ячейки на доске у игрока
    void setBotCellState(QPoint point, int stateNum); // Установка состояния ячейки на доске у бота
    Cell getPlayerCellState(QPoint point); // Получение состояния ячейки на доске у игрока
      Cell getBotCellState(QPoint point); // Получение состояния ячейки на доске у бота
    void printPlayerAllCellStates(); // Печать всех состояний ячеек на доске у игрока
    void printBotAllCellStates(); // Печать всех состояний ячеек на доске у бота
    QVector<Cell> getPlayerAllCells(); // Получение всех ячеек на доске у игрока
    QVector<Cell> getBotAllCells(); // Получение всех ячеек на доске у бота
    bool checkPlayerShipPlacement(); // Проверка размещения кораблей у игрока
    bool checkBotShipPlacement(); // Проверка размещения кораблей у бота
    void syncPlayerShipsCells(); // Синхронизация ячеек кораблей у игрока
    void syncBotShipsCells(); // Синхронизация ячеек кораблей у бота
    void setGameState(GameState newState); // Установка нового состояния игры
    void botRandomShipsPlacing(); // Размещение кораблей бота случайным образом
    void playerShot(QPoint point); // Обработка выстрела игрока
    void botShot(); // Обработка выстрела бота
    QLabel *infoLabel;
    void takeShot(Player* whoShots, Player* whoseField, QPoint point); // Обработка выстрела
    void swapGameState(); // Переключение состояния игры между ходами игрока и бота
    int checkForGameOver(); // Проверка на окончание игры
private:
    GameState gameState;
    Player* player;
    Player* bot;
};

#endif // CONTROLLER_H
