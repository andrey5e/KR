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

MainWindow::~MainWindow() {
    delete gameController;
}

QPoint MainWindow::getCoords(int x, int y, int fieldX, int fieldY) {
    QPoint res;
    res.setX(-1);
    res.setY(-1);
    if (x<fieldX || x>(fieldX+FIELD_WIDTH) || y<fieldY || y>(fieldY+FIELD_HEIGHT)) return res;
    double cfx=1.0*FIELD_WIDTH/10.0;
    double cfy=1.0*FIELD_HEIGHT/10.0;
    res.setX(1.0*(x-fieldX)/cfx);
    res.setY(1.0*(y-fieldY)/cfy);
    return res;
}
