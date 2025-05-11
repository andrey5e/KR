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

#endif // CONTROLLER_H
