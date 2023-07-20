#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "LifeCore.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void startNewGame();

private:
    Ui::MainWindow *ui;

    LifeCore *ptr_core;

};

#endif // MAINWINDOW_H
