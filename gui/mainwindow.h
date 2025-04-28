#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ticTacToe.h"
#include <QMainWindow>
#include <qwidget.h>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    // declaration that mainWindow is a Q Object
    Q_OBJECT

public:
    // variable to hold the game instance
    TicTacToe *m_game;

    // variable that tracks whose turn it is
    char turn = EMPTY_SPACE; // empty_space defined in ticTacToe.h
   
    // constructor and destructor
    explicit MainWindow(QWidget *parent = nullptr, TicTacToe* game = nullptr);
    ~MainWindow();

    // turn determination and swapping logic
    char determineFirstTurn();
    void swapTurn();
    // handles computer turn
    void compTurn();
    // updates the board displayed on the gui
    void updateBoardDisplay();

private slots:
    // button click handler
    void onButtonClicked();

private:    
    // variable to hold UI object
    Ui::MainWindow *ui;

    // map that relates button names to coordinate positions
    map<QString, vector<int>> buttonPos;
};

#endif
