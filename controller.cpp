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
