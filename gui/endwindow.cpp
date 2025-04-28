#include "endwindow.h"
#include "ticTacToe.h"
#include "ui_endwindow.h"
#include <qnamespace.h>

EndWindow::EndWindow(QWidget *parent, MainWindow *mainWindow, char terminalState)
    : QDialog(parent)
    , ui(new Ui::EndWindow)
{
    ui->setupUi(this);

    // set variables
    m_mainWindow = mainWindow;
    m_terminalState = terminalState;

    // connect buttons
    connect(ui->replay, &QPushButton::clicked, this, &EndWindow::onReplayClicked);
    connect(ui->exit, &QPushButton::clicked, this, &EndWindow::onExitClicked);

    // set text based off terminalState
    if(terminalState == DRAW) // draw
    {
        ui->label->setText("It's a draw!");
    }
    else if(terminalState == m_mainWindow->m_game->compMark) // computer win
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
    // set the cursor to a loading symbol
    QApplication::setOverrideCursor(Qt::WaitCursor);

    // reset the main window
    m_mainWindow->resetDisplay();

    // restore the cursor
    QApplication::restoreOverrideCursor();

    // close and delete end window instance
    this->close();
    delete this;
}

// exit button handler
void EndWindow::onExitClicked()
{
    // free all memory and close the game

    // close the main window
    m_mainWindow->close();

    // delete the mainWindow instance
    delete m_mainWindow;
    m_mainWindow = nullptr;

    // close and delete the dialog window
    this->close();
    delete this;

    // close the application
    QApplication::quitOnLastWindowClosed();

}
