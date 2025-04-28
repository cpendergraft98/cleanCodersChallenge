#include "endwindow.h"
#include "ticTacToe.h"
#include "ui_endwindow.h"

EndWindow::EndWindow(QWidget *parent, MainWindow *oldWindow, char terminalState)
    : QDialog(parent)
    , ui(new Ui::EndWindow)
{
    ui->setupUi(this);
    
    // set variables
    m_oldWindow = oldWindow;
    m_terminalState = terminalState;

    // connect buttons
    connect(ui->replay, &QPushButton::clicked, this, &EndWindow::onReplayClicked);
    connect(ui->exit, &QPushButton::clicked, this, &EndWindow::onExitClicked);

    // set text based off terminalState
    if(terminalState == DRAW) // draw
    {
        ui->label->setText("It's a draw!");
    }
    else if(terminalState == oldWindow->m_game->compMark) // computer win
    {
        ui->label->setText("Sorry, you lose!");
    }
    else // player win
    {
        ui->label->setText("You won! How'd you do that?");
    }
}

EndWindow::~EndWindow()
{
    delete ui;
}

// replay button handler
void EndWindow::onReplayClicked()
{
    // close the mainWindow
    m_oldWindow->close();

    // delete the mainwindow instance
    delete m_oldWindow;
    m_oldWindow = nullptr;
    
    // rebuild a game instance
    TicTacToe *game = new TicTacToe();

    // reubuild the mainWindow instance
    MainWindow *newWindow = new MainWindow(nullptr, game);

    // show the new window
    newWindow->show();

    // close and delete end window instance
    this->close();
    delete this;
}

// exit button handler
void EndWindow::onExitClicked()
{
    // free all memory and close the game

    // close the main window
    m_oldWindow->close();

    // delete the mainWindow instance
    delete m_oldWindow;
    m_oldWindow = nullptr;

    // close and delete the dialog window
    this->close();
    delete this;

    // close the application
    QApplication::quitOnLastWindowClosed();

}
