#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPixMap>
#include <QPainter>
#include <QImage>
#include <QVector>
#include <QKeyEvent>
#include <QApplication>
#include "controller.h"

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPoint getCoords(int x, int y, int fieldX, int fieldY); // Получение координат
private:
    GameController* gameController;
protected:
    void mousePressEvent(QMouseEvent *event) override; // Обработка нажатия правой кнопкой мыши
    void paintEvent(QPaintEvent *event) override; // Визуализация игрового поля
    void keyPressEvent(QKeyEvent *event) override; // Обработка нажатий клавиш
};

#endif // MAINWINDOW_H
