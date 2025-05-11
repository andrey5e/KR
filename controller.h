#ifndef CONTROLLER_H
#define CONTROLLER_H

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
    GameState getGameState();
    void createFlots();
    int getPlayerShipCellsCount();
    int getBotShipCellsCount();
    bool isPlayerEmptyCell(QPoint point);
    bool isBotEmptyCell(QPoint point);
    void setPlayerCellState(QPoint point, int stateNum);
    void setBotCellState(QPoint point, int stateNum);
    Cell getBotCellState(QPoint point);
    Cell getPlayerCellState(QPoint point);
    void printPlayerAllCellStates();
    void printBotAllCellStates();
    QVector<Cell> getPlayerAllCells();
    QVector<Cell> getBotAllCells();
    bool checkPlayerShipPlacement();
    bool checkBotShipPlacement();
    void syncPlayerShipsCells();
    void syncBotShipsCells();
    void setGameState(GameState newState);
    void botRandomShipsPlacing();
    void playerShot(QPoint point);
    void botShot();
    QLabel *infoLabel;
    void takeShot(Player* whoShots, Player* whoseField, QPoint point);
    void swapGameState();
    int checkForGameOver();

#endif // CONTROLLER_H
