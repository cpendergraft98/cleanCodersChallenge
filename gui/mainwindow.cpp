#include "mainwindow.h"
#include "endwindow.h"
#include "ui_mainwindow.h"
#include <qmainwindow.h>
#include <qnamespace.h>
#include <random>

MainWindow::MainWindow(QWidget *parent, TicTacToe *newGame)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // assign the provided TicTacToe instance to the game mumber
    m_game = newGame;

    // decide who plays first
    turn = determineFirstTurn();

    // build the ui
    ui->setupUi(this);

    // connect buttons to the button click handler
    connect(ui->topLeft, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->topMid, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->topRight, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->midLeft, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->midMid, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->midRight, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->botLeft, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->botMid, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
    connect(ui->botRight, &QPushButton::clicked, this, &MainWindow::onButtonClicked);

    // map relating buttons to coordinate indecies
    buttonPos = {
        {"topLeft", {0,0}},
        {"topMid", {0,1}},
        {"topRight", {0,2}},
        {"midLeft", {1,0}},
        {"midMid", {1,1}},
        {"midRight", {1,2}},
        {"botLeft", {2,0}},
        {"botMid", {2,1}},
        {"botRight", {2,2}}
    };
    
    // Inform the player of who plays first
    if(turn == m_game->plrMark)
    {
        ui->label->setText("You go first! Your mark is 'X.");
    }
    else
    {
        ui->label->setText("The AI went first! Your mark is 'X' ");

        // run the Ai turn
        compTurn();
    }
}

MainWindow::~MainWindow()
{
    delete m_game;
    delete ui;
}

// handles button clicks
void MainWindow::onButtonClicked()
{
    // get the button that called the function
    QObject* button = sender();

    // get the button name
    QString buttonName = button->objectName();

    // grab the associated grid position from the map
    vector<int> pos = buttonPos[buttonName];

    // place the current players mark on the board
    m_game->placeMark(m_game->mainBoard, pos, turn);

    // update the board
    updateBoardDisplay();

    // check for a terminal state
    char gameState = m_game->checkBoardState(m_game->mainBoard);

    // handle the different game states
    if(gameState == UNFINISHED)
    {
        // the game is not over, swap the turn order
        swapTurn();

        // if the turn is now the AI, call the AI turn function
        if(turn == m_game->compMark)
        {
            compTurn();
        }
    }
    else
    {
        // one of the three terminal states detected

        // instantiate the end game window
        EndWindow* endGame = new EndWindow(nullptr, this, gameState);
        
        // set end game window modality such that it blocks interactions with other windows
        endGame->setWindowModality(Qt::ApplicationModal);
        // display the end window
        endGame->show();
    }
}

// randomly choses if the player or the AI will start
char MainWindow::determineFirstTurn()
{
    // build random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 1);

    // randomly select between 0 and 1
    int whoseTurn = dist(gen);

    if(whoseTurn == 0)
    {
        // AI turn
        return m_game->compMark;
    }
    else
    {
        // Player turn
        return m_game->plrMark;
    }
}

// swaps turns between the player and the AI
void MainWindow::swapTurn()
{
    // check current turn state
    if(turn == m_game->compMark)
    {
        // swap to player turn
        turn = m_game->plrMark;
    }
    else
    {
        // swap to AI turn
        turn = m_game->compMark;
    }
}

void MainWindow::compTurn()
{
    // get the best move
    vector<int> bestMove = m_game->getBestMove();
    int row = bestMove[0];
    int col = bestMove[1];

    QString clickButtonName;

    // find the button name that matches the bestMove
    for(const auto& entry : buttonPos)
    {
        if(entry.second[0] == row && entry.second[1] == col)
        {
            clickButtonName = entry.first;
        }
    }
    
    // grab the button instance associated with the identified button name
    QPushButton *button = findChild<QPushButton*>(clickButtonName);
    
    // 'press' the button
    button->click();
}

// checks the mainBoard instance in the backend and updates markers 
// on the GUI
void MainWindow::updateBoardDisplay()
{
    // check each button and position pair in buttonPos
    for(const auto& entry : buttonPos)
    {
        const QString name = entry.first;
        int row = entry.second[0];
        int col = entry.second[1];

        // grab the corresponding button
        QPushButton *button = findChild<QPushButton*>(name);
        
        // check if corresponding position on the game board has a marker other than EMPTY_SPACE
        if(m_game->mainBoard[row][col] != EMPTY_SPACE)
        {
            // update the button text to reflect the marker
            button->setText(QString(m_game->mainBoard[row][col]));
            // disable the button so the position cannot be used again
            button->setEnabled(false);
        }
    }
}

// resets the display for a new game
void MainWindow::resetDisplay()
{
    // reset the game board
    m_game->resetBoard();

    // reset all text and re-enable buttons
    for(const auto& entry: buttonPos)
    {
        // get the name of the button
        const QString name = entry.first;

        // grab the corresponding button
        QPushButton *button = findChild<QPushButton*>(name);

        // set the button text
        button->setText(" ");
        // re-enable the button
        button->setEnabled(true);
    }

    // re-determine who plays first
    turn = determineFirstTurn();

    // Inform the player of who plays first
    if(turn == m_game->plrMark)
    {
        ui->label->setText("You go first! Your mark is 'X.");
    }
    else
    {
        ui->label->setText("The AI went first! Your mark is 'X' ");

        // run the Ai turn
        compTurn();
    }

}
