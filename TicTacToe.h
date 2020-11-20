//Nguyen Dinh Luong (StudentID: 19617187)
/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from any other student’s work or from any other source. No part of the code has been written/produced for me by another person or copied from any other source.
I hold a copy of this assignment that I can produce if the original is lost or damaged.
**************************/

#ifndef TICTACTOE_CORRECT_VERSION__TICTACTOE_H
#define TICTACTOE_CORRECT_VERSION__TICTACTOE_H
#include "vector"
using namespace std;

enum Status {NONE, TIE, O, X};
class TicTacToe
{
public:
    TicTacToe();
    void initBoard();
    void displayBoard();
    vector<int> allPossibleMoves(); // for AI player
    void setChar(char symbol, int i); // for AI player
    void resetWinner(); // for AI player
    int move(int cell, char turn);
    Status update();
    Status getStatus();
    char board[3][3];
private:
    Status gameStatus;
};
#endif //TICTACTOE_CORRECT_VERSION__TICTACTOE_H
