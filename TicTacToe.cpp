//Nguyen Dinh Luong (StudentID: 19617187)
/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from any other student’s work or from any other source. No part of the code has been written/produced for me by another person or copied from any other source.
I hold a copy of this assignment that I can produce if the original is lost or damaged.
**************************/

#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
    initBoard();
    gameStatus = NONE;
}
void TicTacToe::initBoard() {
    for(int x = 0; x < 3; ++x)
        for(int y = 0; y < 3; ++y)
            board[x][y] = ' ';
}

Status TicTacToe::getStatus()
{
    return gameStatus;
}

int TicTacToe::move(int cell, char turn)
{
    cell = cell - 1;
    if(board[cell/3][cell%3] == ' ') {
        board[cell/3][cell%3] = turn;
        return 1;
    }
    return 0;  // cell already occupied
}

void TicTacToe :: resetWinner()
{
    gameStatus = NONE;
}

vector<int> TicTacToe:: allPossibleMoves()
{
    vector<int> move_set;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                move_set.push_back(3 * i + j);
        }
    }
    return move_set;
}

void TicTacToe:: setChar(char symbol, int i)
{
    board[i / 3][i % 3] = symbol;
}

Status TicTacToe::update()
{
    bool tie = true;
    /* check for a tie */
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] == ' ')
                tie = false;

    if(tie) {
        gameStatus = TIE;
        return TIE;
    }

    /* DIAGONALS */
    /* top-left to bottom-right */
    if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if(board[0][0] == 'X') {
            gameStatus = X;
        } else {
            gameStatus = O;
        }
        return gameStatus; // return winner
    }

    /* top-right to bottom-left */
    if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if(board[0][2] == 'X') {
            gameStatus = X;
        } else {
            gameStatus = O;
        }
        return gameStatus; // return winner
    }

    /* COLUMNS */
    for(int column = 0; column < 3; column++)
    {
        if(board[0][column] == board[1][column] && board[0][column] != ' ' && board[1][column] == board[2][column]) {
            if(board[0][column] == 'X') {
                gameStatus = X;
            } else {
                gameStatus = O;
            }
            return gameStatus; // return winner
        }
    }

    /* ROWS */
    for(int row = 0; row < 3; row++)
    {
        if(board[row][0] != ' ' && board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if(board[row][0] == 'X') {
                gameStatus = X;
            } else {
                gameStatus = O;
            }
            return gameStatus; // return winner
        }
    }

    return NONE; // no one has won yet
}
