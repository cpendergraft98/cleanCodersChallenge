#include "prototypes.h"
#include <random>

// implmentation of the game loop
void gameLoop(TicTacToe* game, int whoseTurn)
{
    // check the current game state
    char gameState = game->checkBoardState(game->mainBoard);

    // run the gameLoop as long as the game is in an Unfinished state
    while(gameState == UNFINISHED)
    {
        // display the board
        game->printBoard(game->mainBoard);

        // computer turn
        if(whoseTurn == 0)
        {
            cout << "The AI is making its move..." << endl << endl; 
            game->computerTurn();

            // pass turn to the player
            whoseTurn = 1;
        }
        else // player turn
        {
            vector<int> position = {0, 0};

            cout << "Choose the row index of your move: ";
            cin >> position.at(0);
            cout << endl;

            cout << "Choose the col index of your move: ";
            cin >> position.at(1);
            cout << endl;

            game->placeMark(game->mainBoard, position, game->plrMark);

            // pass turn to the AI
            whoseTurn = 0;
        }

        gameState = game->checkBoardState(game->mainBoard);
    }

    // output the final board
    game->printBoard(game->mainBoard);

    // Evaluate the winner
    if(gameState == game->compMark)
    {
        cout << "Sorry, the AI beat you!" << endl << endl;
    }
    else if(gameState == DRAW)
    {
        cout << "It's a draw!" << endl << endl;
    }
    else // the player wins
    {
        cout << "You win!" << endl << endl;
    }
}

int main()
{
    bool play = true; // assume at least one round
    char response; // stores user response to replay query
    while(play)
    {
        // generate the game instance
        TicTacToe* game = new TicTacToe();

        // randomly decide who goes first
        random_device rd;
        mt19937 gen(rd());
        // generate a number between 0 (computer) and 1(player)
        uniform_int_distribution<>dist(0, 1);
        int whoseTurn = dist(gen);

        // run the gameplay loop
        gameLoop(game, 1);

        // delete instance of game after
        delete game;

        // query user to play again
        cout << "Play again? [y|n]: ";
        cin >> response;
        cout << endl;

        // update play to false if response is no
        if(response == 'n')
        {
            play = false;
        }
    }
    cout << endl << "Thanks for playing!" << endl;
    return EXIT_SUCCESS;
}
