#include "prototypes.h"
#include <string>

// implementation of TicTacToe class methods

// Constructor
TicTacToe::TicTacToe()
{
    // Init number of rows, cols, and turns
    boardRows = 3; // 3x3 fixed size
    boardCols = 3;

    // set player and computer markers
    plrMark = 'X'; // player is X
    compMark = 'O'; // comp is O
    
    // build a 3x3 vector grid
    mainBoard = buildBoard();
}


// builds boardRows x boardCols boards
vector<vector<char>> TicTacToe::buildBoard()
{
    // initialize new board
    vector<vector<char>> newBoard = {};

    // create rows
    for(int row = 0; row < boardRows; row++)
    {
        // add a new row to the board
        newBoard.push_back({});

        // create cols
        for(int col = 0; col < boardCols; col++)
        {
            // insert empty spaces in each col
            newBoard.at(row).push_back(EMPTY_SPACE);
        }
    }

    return newBoard;
}


// Determines avaialble positions in the provided board
vector<vector<int>> TicTacToe::availablePositions(vector<vector<char>> &srcBoard)
{
    // parent vector to hold child vectors
    vector<vector<int>> available = {};
    
    // tracks insertion index within available
    int avIdx = 0;

    // store the indexes available board spaces
    for(int row = 0; row < boardRows; row++)
    {
        for (int col = 0; col < boardCols; col++)
        {
            // if the row, col position is empty, store it
            if(srcBoard.at(row).at(col) == EMPTY_SPACE)
            {
                // push a new empty vector into available
                available.push_back({}); // will naturally be placed at avIdx
                
                // add row, col to newly created sub-vector
                available.at(avIdx).push_back(row);
                available.at(avIdx).push_back(col);

                // increment internal index tracker
                avIdx++;
            }
        }
    }

    return available;
}

// checks if the provided board is full
bool TicTacToe::isBoardFull(vector<vector<char>> &srcBoard)
{
    // counter variable to track the number of populated positions
    int usedSpaces = 0;

    for(int row = 0; row < boardRows; row++)
    {
        for(int col = 0; col < boardCols; col++)
        {
            if(srcBoard.at(row).at(col) != EMPTY_SPACE)
            {
                usedSpaces++;
            }
        }
    }

    return (usedSpaces == 9);
}

// places mark on srcBoard at the given position
void TicTacToe::placeMark(vector<vector<char>> &srcBoard, vector<int> position, char mark)
{
    // extract row and col (for code legibility)
    int row = position.at(0);
    int col = position.at(1);

    // place corresponding mark on srcBoard
    srcBoard.at(row).at(col) = mark;
}

// checks the state of the board to determine if the game has ended
char TicTacToe::checkBoardState(vector<vector<char>> &srcBoard)
{
    // if plr or AI win, returns the winners mark
    // if a draw, returns DRAW marker
    // if the game is not over, returns UNFINISHED marker
    
    // check for horizontal victory
    for(int row = 0; row < boardRows; row++)
    {
        if((srcBoard.at(row).at(0) != EMPTY_SPACE) && (srcBoard.at(row).at(0) 
            == srcBoard.at(row).at(1)) && (srcBoard.at(row).at(0) == srcBoard.at(row).at(2)))
        {
            // return the mark of the winner
            return srcBoard.at(row).at(0);
        }
    }

    // check for vertical victory
    for(int col = 0; col < boardCols; col++)
    {
        if((srcBoard.at(0).at(col) != EMPTY_SPACE) && (srcBoard.at(0).at(col) 
            == srcBoard.at(1).at(col)) && (srcBoard.at(0).at(col) == srcBoard.at(2).at(col)))
        {
            // return the mark of the winner
            return srcBoard.at(0).at(col);
        }
    }

    // check for top left -> bottom right diag victory
    if((srcBoard.at(0).at(0) != EMPTY_SPACE) && ((srcBoard.at(0).at(0) == srcBoard.at(1).at(1)) 
        && (srcBoard.at(0).at(0) == srcBoard.at(2).at(2))))
    {
        // return the mark of the winner
        return srcBoard.at(0).at(0);
    }

    // check for top right -> bottom left diag victory
    if((srcBoard.at(0).at(2) != EMPTY_SPACE) && ((srcBoard.at(0).at(2) == srcBoard.at(1).at(1)) 
        && (srcBoard.at(0).at(2) == srcBoard.at(2).at(0))))
    {
        // return the mark of the winner
        return srcBoard.at(0).at(2);
    }

    // if none of the pervious checks trigger, but the board is full, we have a draw
    if(isBoardFull(srcBoard))
    {
        return DRAW;
    }

    // base case: the game is unfinished
    return UNFINISHED;

}

// performs the minimax algorithm to determine optimal next move
int TicTacToe::minimax(vector<vector<char>> &srcBoard, bool isComputerTurn, int depth, string traceID)
{
    // var to store the current board state
    char boardState = checkBoardState(srcBoard);
    
    int score;

    // base case: the game has ended
    if(boardState != UNFINISHED)
    {
        // check what state the game finished in
        if(boardState == compMark) // AI victory
        {
            score = 10 - depth;
        }
        else if(boardState == plrMark) // player victory
        {
            score = depth - 10;
        }
        else // draw
        {
            score = 0;
        }

        cout << "[TERMINAL] " << traceID << " | Depth: " << depth 
            << " | Score: " << score << endl << endl;

        return score;
    }

    // if it is the computers turn (maximizing)
    if(isComputerTurn)
    {
        // initialize bestScore
        int bestScore = numeric_limits<int>::min();
        
        // identify indexes of available positions
        vector<vector<int>> available = availablePositions(srcBoard);

        // place a mark at every empty spot on the copiedBoard
        for(int idx = 0; idx < (int)available.size(); idx++)
        {
            // create copy of the source board to test each new move
            vector<vector<char>> copiedBoard = srcBoard;

            // make the move
            placeMark(copiedBoard, available.at(idx), compMark);

            // generate next moveID
            string nextTrace = traceID + "->" + to_string(available.at(idx).at(0)) + "," + to_string(available.at(idx).at(1));

            // recursively call minimax on the new board state, set to player turn, store output score
            score = minimax(copiedBoard, false, depth + 1, nextTrace);

            // update the best score with the new best
            if(score > bestScore)
            {
                bestScore = score;
            }
        }

        cout << "[RETURN-AI] " << traceID << " | BestScore: " << bestScore 
            << " | Depth: " << depth << endl << endl;
        return bestScore;
    }
    else // player turn (minimizing)
    {
        // initialize bestScore
        int bestScore = numeric_limits<int>::max();
        
        // identify indexes of available positions
        vector<vector<int>> available = availablePositions(srcBoard);

        // place a mark at every empty spot on the copied board
        for(int idx = 0; idx < (int)available.size(); idx++)
        {
            // create a copy of the source board to test each new move
            vector<vector<char>> copiedBoard = srcBoard;

            // make the move
            placeMark(copiedBoard, available.at(idx), plrMark);

            // generate next moveID
            string nextTrace = traceID + "->" + to_string(available.at(idx).at(0)) + "," + to_string(available.at(idx).at(1));

            // recursively call minimax on the new board state, set to comp turn, store output score
            score = minimax(copiedBoard, true, depth + 1, nextTrace);

            // update the best score with the new best
            if(score < bestScore)
            {
                bestScore = score;
            }
        }

        cout << "[RETURN-PLR] " << traceID << " | BestScore: " << bestScore 
            << " | Depth: " << depth << endl << endl;
        return bestScore;
    }
}

// determines optimal position for AI to make its move
vector<int> TicTacToe::getBestMove()
{
    // stores the score returned from the minimax call
    int moveScore;

    // stores the best overall score, initialized to something large
    int bestScore = numeric_limits<int>::min();
    
    // store the move associated with the best score
    vector<int> bestMove;

    // generate list of available moves 
    vector<vector<int>> available = availablePositions(mainBoard);

    /*
    ////////////////////// HARDCODED TEST ///////////////////////////////////////////////////
    
    vector<vector<char>> board = {{'O', 'O', '_'},{'X', 'X', '_'},{'_', '_', '_'}};
    
    cout << "RUNNING TEST WITH BOARD:" << endl;
    printBoard(board);

    // generate available spaces
    vector<vector<int>> available = availablePositions(board);

    for(int idx = 0; idx < (int)available.size(); idx++)
    {
        vector<vector<char>> copiedBoard = board;

        placeMark(copiedBoard, available.at(idx), compMark);

        cout << "SIMULATING FROM BOARD:" << endl;
        printBoard(copiedBoard);

        // generate moveID     
        string moveID = to_string(available.at(idx).at(0)) + "," +to_string(available.at(idx).at(1));

        // call minimax
        moveScore = minimax(copiedBoard, false, 0, "ROOT->"+moveID);
        
        if(moveScore > bestScore)
        {
            bestScore = moveScore;
            bestMove = available.at(idx);
        }
    }
    
    cout << "===========================" << endl;
    // log the score returned from minimax
    cout << "Final Best Score: " << bestScore << endl;
    cout << "Final Best Move: " << "(" << bestMove.at(0) << ", " << bestMove.at(1) << ")" << endl;
    cout << "===========================" << endl;

    //////////////////////////////////////////////////////////////////////////////////////////
    */

    // iterate over list of possible moves
    for(int idx = 0; idx < (int)available.size(); idx++)
    {
        // make a copy of the current board
        vector<vector<char>> copiedBoard = mainBoard;

        // place the marker at the board position
        placeMark(copiedBoard, available.at(idx), compMark);

        // generate moveID
        string moveID = to_string(available.at(idx).at(0)) + "," +to_string(available.at(idx).at(1));

        // call Minimax
        moveScore = minimax(copiedBoard, false, 0, "ROOT->" + moveID);

        if(moveScore > bestScore)
        {
            bestMove = available.at(idx);
            bestScore = moveScore;
        }
    }
    
    return bestMove;
}

// handles the computers turn
void TicTacToe::computerTurn()
{
    // identify and store the best move
    vector<int> bestMove = getBestMove();

    // place a marker in the identified space
    placeMark(mainBoard, bestMove, compMark);
}

// debug function to print formatted board to the CLI
void TicTacToe::printBoard(vector<vector<char>> srcBoard)
{
    for(int row = 0; row < boardRows; row++)
    {
        for(int col = 0; col < boardCols; col++)
        {
            cout << srcBoard.at(row).at(col) << " ";
        }
        cout << endl;
    }
}
