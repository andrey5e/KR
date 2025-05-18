#include "controller.h"

GameController::GameController() {
    gameState = GameState::SHIPS_PLACING;
    player = new HumanPlayer(); // Создание игрока
    bot = new AIPlayer(); // Создание бота
    createFlots(); // Создание флотов для игрока и бота
}

GameController::~GameController() {
    delete player; // Удаление игрока
    delete bot; // Удаление бота
}

// Получение текущего состояния игры
GameState GameController::getGameState() {
    return gameState;
}

// Создание флотов для игрока и бота
void GameController::createFlots() {
    player->createFlot(); // Создание флота для игрока
    bot->createFlot(); // Создание флота для бота
}

// Подсчёт количества ячеек с кораблями на доске игрока
int getShipCellsCount(Player* somePlayer) {
    int count = 0;
    Board* board = somePlayer->getBoard();
    for (int i {0}; i < 10; i++) {
        for (int j {0}; j < 10; j++) {
            if (board->getCellState(QPoint(j, i)) == Cell::SHIP)
                count++;
        }
    }
    return count;
}

// Получение количества ячеек с кораблями у игрока
int GameController::getPlayerShipCellsCount() {
    return getShipCellsCount(player);
}

// Получение количества ячеек с кораблями у бота
int GameController::getBotShipCellsCount() {
    return getShipCellsCount(bot);
}

// Проверка, является ли ячейка пустой
bool isEmptyCell(Player* somePlayer, QPoint point) {
    Board* board = somePlayer->getBoard();
    return board->getCellState(point) == Cell::EMPTY;
}

// Проверка, является ли ячейка пустой у игрока
bool GameController::isPlayerEmptyCell(QPoint point) {
    return isEmptyCell(player, point);
}

// Проверка, является ли ячейка пустой у бота
bool GameController::isBotEmptyCell(QPoint point) {
    return isEmptyCell(bot, point);
}

// Установка состояния ячейки на доске
void setCellState(Player* somePlayer, QPoint point, int stateNum) {
    Board* board = somePlayer->getBoard();
    board->setCellState(point, static_cast<Cell>(stateNum));
}

// Установка состояния ячейки на доске у бота
void GameController::setBotCellState(QPoint point, int stateNum) {
    return setCellState(bot, point, stateNum);
}

// Получение состояния ячейки на доске
Cell getCellState(QPoint point, Player* somePlayer) {
    Board *board = somePlayer->getBoard();
    return board->getCellState(point);
}

// Получение состояния ячейки на доске у бота
Cell GameController::getBotCellState(QPoint point) {
    return getCellState(point, bot);
}

// Получение состояния ячейки на доске у игрока
Cell GameController::getPlayerCellState(QPoint point) {
    return getCellState(point, player);
}

// Установка состояния ячейки на доске у игрока
void GameController::setPlayerCellState(QPoint point, int stateNum) {
    return setCellState(player, point, stateNum);
}

// Печать всех состояний ячеек на доске
void printAllCellStates(Player* somePlayer) {
    somePlayer->getBoard()->printBoardStates();
}

// Печать всех состояний ячеек на доске у игрока
void GameController::printPlayerAllCellStates() {
    printAllCellStates(player);
}

// Печать всех состояний ячеек на доске у бота
void GameController::printBotAllCellStates() {
    printAllCellStates(bot);
}
