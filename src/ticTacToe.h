//TODO: Get rid of any unused members/functions

#ifndef PROTOTYPES_H
#define PROTOTYPES_H

// Libraries
#include <cctype>
#include <string>
#include <vector>
using namespace std;

// Global var for empty spaces
const char EMPTY_SPACE = '_';

// Global var to indicate draw state & unfinished game state
const char DRAW = 'D';
const char UNFINISHED = 'U';

// Simple class implementing the board
class TicTacToe
{
    public:

    // vars to store rows and cols
    int boardRows;
    int boardCols;

    // markers for the player and the computer
    char plrMark;
    char compMark;
    // tracks the number of turns taken
    
    // vector of vectors of chars for the board
    vector<vector<char>> mainBoard;
        
    // constructor
    TicTacToe();
    // no manual memory allocation -> no custom destructor needed
    
    // methods and helper functions
    vector<vector<char>> buildBoard(); // builds boardRows x boardCols boards
    bool isBoardFull(vector<vector<char>> &srcBoard); // determines if provided board is full
    vector<vector<int>> availablePositions(vector<vector<char>> &srcBoard); // returns a vector of unused positions in the board
    void placeMark(vector<vector<char>> &srcBoard, vector<int> position, char mark); // places mark on srcBoard at the given position
    char checkBoardState(vector<vector<char>> &srcBoard); // determines if the game has ended
    int minimax(vector<vector<char>> &srcBoard, bool isComputerTurn, int depth, string traceID); // minimax algorithm implementation
    vector<int> getBestMove(); // Uses minimax to determine optimal move
};

#endif
