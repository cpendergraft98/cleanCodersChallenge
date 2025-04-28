#include "startwindow.h"
#include "mainwindow.h"
#include "ticTacToe.h"
#include "ui_startwindow.h"
#include <qnamespace.h>
#include <qpushbutton.h>
#include <qtextcursor.h>

StartWindow::StartWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    // connect buttons
    connect(ui->play, &QPushButton::clicked, this, &StartWindow::onPlayClicked);
    connect(ui->exit, &QPushButton::clicked, this, &StartWindow::onExitClicked);
}

StartWindow::~StartWindow()
{
    delete ui;
}

// play button handler
void StartWindow::onPlayClicked()
{
    // set loading cursor
    QApplication::setOverrideCursor(Qt::WaitCursor);

    // build a tic tac toe game instance
    TicTacToe* game = new TicTacToe();

    // build a new main window instance
    MainWindow* mainWindow = new MainWindow(nullptr, game);

    // reset cursor
    QApplication::restoreOverrideCursor();

    // display the mainWindow
    mainWindow->show();

    // close and delete the start window
    this->close();
    delete this;
}

// exit button handler
void StartWindow::onExitClicked()
{
    // delete the start window instance
    this->close();
    delete this;
}
