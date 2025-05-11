#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setFixedSize(555, 309);
    gameController = new GameController();
        
    // Отладка
    qDebug() << "Главное окно создано, контроллер инициализирован";

    // Создание фона
    QPalette pal;
    pal.setBrush(QPalette::Active, QPalette::Window, QBrush(QPixmap(":/images/background.png")));
    this->setPalette(pal);

    // Интеграция кнопки
    gameController->infoLabel = new QLabel(this);
    gameController->infoLabel->move(200, 260);
    gameController->infoLabel->setText("Расставьте корабли!");
    gameController->infoLabel->setFixedSize(170, 40);
    gameController->infoLabel->setStyleSheet("font-weight: bold; border-style: outset; border-width: 2px; border-radius: 10px;");
    gameController->infoLabel->setAlignment(Qt::AlignCenter);
}
