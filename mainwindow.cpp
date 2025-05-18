#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setFixedSize(555, 289); // Установка размера главного окна
    gameController = new GameController(); // Инициализация контроллера игры
    qDebug() << "Главное окно создано, контроллер инициализирован"; // Отладка
    QPalette pal;
    pal.setBrush(QPalette::Active, QPalette::Window, QBrush(QPixmap("C:/LR/field.png"))); // Установка фона главного окна
    this->setPalette(pal);
    gameController->infoLabel = new QLabel(this);
    gameController->infoLabel->move(200, 260);
    gameController->infoLabel->setText("Разверните флот!");
    gameController->infoLabel->setFixedSize(150, 28);
    gameController->infoLabel->setStyleSheet("font-weight: bold; border-style: outset; border-width: 1px; border-radius: 5px;");
    gameController->infoLabel->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow() {
    delete gameController; // Освобождение памяти при уничтожении главного окна
}

// Получение координат
QPoint MainWindow::getCoords(int x, int y, int fieldX, int fieldY) {
    QPoint res;
    res.setX(-1);
    res.setY(-1);
    if (x < fieldX || x > (fieldX + FIELD_WIDTH) || y < fieldY || y > (fieldY + FIELD_HEIGHT)) return res;
    double cfx = 1.0 * FIELD_WIDTH / 10.0;
    double cfy = 1.0 * FIELD_HEIGHT / 10.0;
    res.setX(1.0 * (x - fieldX) / cfx);
    res.setY(1.0 * (y - fieldY) / cfy);
    return res;
}

// Обработка нажатия кнопки мыши
void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        QPoint pos = event->pos(); // Получение позиции курсора
        qDebug() << "Mouse click at (" << pos.x() << "," << pos.y() << ")"; // Отладка
        qDebug() << "\nПоле бота:";
        gameController->printBotAllCellStates();
    }
    else if (event->button() == Qt::LeftButton) {
        if (gameController->getGameState() == GameState::SHIPS_PLACING) {
            QPointF pos = event->position();
            if (pos.x() >= MYFIELD_X && pos.x() <= FIELD_WIDTH + MYFIELD_X
                && pos.y() >= MYFIELD_Y && pos.y() <= FIELD_HEIGHT + MYFIELD_Y) {
                QPoint qp = getCoords(pos.x(), pos.y(), MYFIELD_X, MYFIELD_Y);
                if (qp.x() == 10) qp.setX(9);
                if (qp.y() == 10) qp.setY(9);
                if (gameController->isPlayerEmptyCell(qp)) {
                    if (gameController->getPlayerShipCellsCount() < 20) {
                        gameController->setPlayerCellState(qp, 2);
                        if (gameController->checkPlayerShipPlacement()) {
                            gameController->infoLabel->setText("Начать игру");
                        }
                    }
                } else {
                    gameController->setPlayerCellState(qp, 0);
                    gameController->infoLabel->setText("Разверните флот!");
                }
                update();
            }
        }
        else if (gameController->getGameState() == GameState::PLAYER_TURN) {
            QPointF pos = event->position();
            if (pos.x() >= ENEMYFIELD_X && pos.x() <= FIELD_WIDTH + ENEMYFIELD_X
                && pos.y() >= ENEMYFIELD_Y && pos.y() <= FIELD_HEIGHT + ENEMYFIELD_Y) {
                QPoint qp = getCoords(pos.x(), pos.y(), ENEMYFIELD_X, ENEMYFIELD_Y);
                if (qp.x() == 10) qp.setX(9);
                if (qp.y() == 10) qp.setY(9);
                gameController->playerShot(qp);
                repaint();
                QApplication::processEvents();
                // Проверка на завершение игры
                int gO_status = gameController->checkForGameOver();
                if (gameController->checkForGameOver() != 0) {
                    if (gO_status == 2) {
                        gameController->setGameState(GameState::GAMEOVER);
                        gameController->infoLabel->setText("Победа!");
                    } else {
                        gameController->setGameState(GameState::GAMEOVER);
                        gameController->infoLabel->setText("Поражение!");
                    }
                }
                // Ход бота
                while (gameController->getGameState() == GameState::ENEMY_TURN) {
                    gameController->botShot(); // Выстрел
                    repaint();
                    QApplication::processEvents();
                    // Проверка на завершение игры
                    int gO_status = gameController->checkForGameOver();
                    if (gameController->checkForGameOver() != 0) {
                        if (gO_status == 2) {
                            gameController->setGameState(GameState::GAMEOVER);
                            gameController->infoLabel->setText("Победа!");
                        } else {
                            gameController->setGameState(GameState::GAMEOVER);
                            gameController->infoLabel->setText("Поражение!");
                        }
                    }
                }
            }
        }
    }
}
