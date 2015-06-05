#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <gaming.h>
#include <QLabel>
#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QBitmap>
#include <QKeyEvent>
#include "time.h"
#include <iostream>
#include <cmath>
#include <string.h>



using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void print();
    void Location(int i, int j, int n);
    void keyPressEvent(QKeyEvent *e);
    void picOn(int n, QLabel *pic);
    void reset();
    void result(int matrix[][4]);

private:
    Ui::MainWindow *ui;
    QWidget *mainWindow;

    int matrix[4][4];
    int score = 0;



private slots:
    void startClick();


};

#endif // MAINWINDOW_H
