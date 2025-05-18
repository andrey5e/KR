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

// Получение всех ячеек на доске
QVector<Cell> getAllCells(Player* somePlayer) {
    return somePlayer->getBoard()->getCells();
}

// Получение всех ячеек на доске у игрока
QVector<Cell> GameController::getPlayerAllCells() {
    return getAllCells(player);
}

// Получение всех ячеек на доске у бота
QVector<Cell> GameController::getBotAllCells() {
    return getAllCells(bot);
}

// Проверка, находится ли корабль в заданной позиции
bool isShip(Player* somePlayer, int size, int x, int y) {
    Board* board = somePlayer->getBoard();
    if (x > 0 && board->getCellState(QPoint(x - 1, y)) != Cell::EMPTY)
        return false;
    if (y > 0 && board->getCellState(QPoint(x, y - 1)) != Cell::EMPTY)
        return false;
    if (board->getCellState(QPoint(x, y)) == Cell::EMPTY)
        return false;
    int tmp = x;
    int num = 0;
    while (board->getCellState(QPoint(tmp, y)) != Cell::EMPTY && tmp < 10) {
        tmp++;
        num++;
    }
    if (num == size) {
        if (board->getCellState(QPoint(x, y + 1)) != Cell::EMPTY)
            return false;
        if (board->getCellState(QPoint(x - 1, y - 1)) != Cell::EMPTY || board->getCellState(QPoint(x - 1, y + 1)) != Cell::EMPTY
            || board->getCellState(QPoint(x + size, y - 1)) != Cell::EMPTY || board->getCellState(QPoint(x + size, y + 1)) != Cell::EMPTY)
            return false;
        return true;
    }
    tmp = y;
    num = 0;
    while (board->getCellState(QPoint(x, tmp)) != Cell::EMPTY && tmp < 10) {
        tmp++;
        num++;
    }
    if (num == size) {
        if (board->getCellState(QPoint(x + 1, y)) != Cell::EMPTY)
            return false;
        if (board->getCellState(QPoint(x - 1, y - 1)) != Cell::EMPTY || board->getCellState(QPoint(x + 1, y - 1)) != Cell::EMPTY
            || board->getCellState(QPoint(x - 1, y + size)) != Cell::EMPTY || board->getCellState(QPoint(x + 1, y + size)) != Cell::EMPTY)
            return false;
        return true;
    }
    return false;
}

// Подсчёт количества кораблей заданного размера на доске
int shipNum(Player* somePlayer, int size) {
    int shipNumber = 0;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            if(isShip(somePlayer, size, j, i))
                shipNumber++;
    return shipNumber;
}

// Проверка размещения кораблей на доске (20)
bool checkShipPlacement(Player* somePlayer) {
    if (getShipCellsCount(somePlayer) == 20) {
        if (shipNum(somePlayer, 1) == 4 &&
            shipNum(somePlayer, 2) == 3 &&
            shipNum(somePlayer, 3) == 2 &&
            shipNum(somePlayer, 4) == 1) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

// Проверка размещения кораблей у игрока
bool GameController::checkPlayerShipPlacement() {
    return checkShipPlacement(player);
}

// Проверка размещения кораблей у бота
bool GameController::checkBotShipPlacement() {
    return checkShipPlacement(bot);
}

// Синхронизация ячеек кораблей на доске
void syncShipsCells(Player* somePlayer) {
    Board* board = somePlayer->getBoard();
    QPoint fourPartShip;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (isShip(somePlayer, 4, j, i)) {
                fourPartShip.setX(j);
                fourPartShip.setY(i);
            }
    QPoint threePartShip1(-1, -1);
    QPoint threePartShip2(-1, -1);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (isShip(somePlayer, 3, j, i)) {
                if (threePartShip1.x() == -1) {
                    threePartShip1.setX(j);
                    threePartShip1.setY(i);
                } else {
                    threePartShip2.setX(j);
                    threePartShip2.setY(i);
                }
            }
    QPoint twoPartShip1(-1, -1);
    QPoint twoPartShip2(-1, -1);
    QPoint twoPartShip3(-1, -1);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (isShip(somePlayer, 2, j, i)) {
                if (twoPartShip1.x() == -1) {
                    twoPartShip1.setX(j);
                    twoPartShip1.setY(i);
                } else if (twoPartShip2.x() == -1) {
                    twoPartShip2.setX(j);
                    twoPartShip2.setY(i);
                } else {
                    twoPartShip3.setX(j);
                    twoPartShip3.setY(i);
                }
            }
    QPoint onePartShip1(-1, -1);
    QPoint onePartShip2(-1, -1);
    QPoint onePartShip3(-1, -1);
    QPoint onePartShip4(-1, -1);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (isShip(somePlayer, 1, j, i)) {
                if (onePartShip1.x() == -1) {
                    onePartShip1.setX(j);
                    onePartShip1.setY(i);
                } else if (onePartShip2.x() == -1) {
                    onePartShip2.setX(j);
                    onePartShip2.setY(i);
                } else if (onePartShip3.x() == -1){
                    onePartShip3.setX(j);
                    onePartShip3.setY(i);
                } else {
                    onePartShip4.setX(j);
                    onePartShip4.setY(i);
                }
            }
    // Синхронизация координат кораблей на доске
    for (Ship* ship : board->getFlot()) {
        if (ship->getWeight() == 4) {
            ship->setCoords(fourPartShip);
        } else if (ship->getWeight() == 3) {
            if (threePartShip1.x() != -1) {
                ship->setCoords(threePartShip1);
                threePartShip1.setX(-1);
            } else {
                ship->setCoords(threePartShip2);
            }
        } else if (ship->getWeight() == 2) {
            if (twoPartShip1.x() != -1) {
                ship->setCoords(twoPartShip1);
                twoPartShip1.setX(-1);
            } else if (twoPartShip2.x() != -1) {
                ship->setCoords(twoPartShip2);
                twoPartShip2.setX(-1);
            } else {
                ship->setCoords(twoPartShip3);
            }
        } else {
            if (onePartShip1.x() != -1) {
                ship->setCoords(onePartShip1);
                onePartShip1.setX(-1);
            } else if (onePartShip2.x() != -1) {
                ship->setCoords(onePartShip2);
                onePartShip2.setX(-1);
            } else if (onePartShip3.x() != -1) {
                ship->setCoords(onePartShip3);
                onePartShip3.setX(-1);
            } else {
                ship->setCoords(onePartShip4);
            }
        }
    }
    board->prettyPrintFlot();
}
