#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller.h"
#include <QMouseEvent>
#include <QPixMap>
#include <QPainter>
#include <QImage>
#include <QVector>
#include <QKeyEvent>
#include <QApplication>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPoint getCoordsPlayer(int x, int y);
    QPoint getCoords(int x, int y, int fieldX, int fieldY);
private:
    GameController* gameController;

#endif // MAINWINDOW_H
