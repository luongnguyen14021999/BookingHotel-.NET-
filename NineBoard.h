//Nguyen Dinh Luong (StudentID: 19617187)
/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from any other student’s work or from any other source. No part of the code has been written/produced for me by another person or copied from any other source.
I hold a copy of this assignment that I can produce if the original is lost or damaged.
**************************/

#ifndef TICTACTOE_CORRECT_VERSION__NINEBOARD_H
#define TICTACTOE_CORRECT_VERSION__NINEBOARD_H
#include "TicTacToe.h"

struct BoardCoordinate {
public:
    int Xcoordinate;
    int Ycoordinate;
};

struct ttt_move
{
    int index;
    long score;
};

class NineBoard {
public:
    NineBoard();

    void displayBoards();

    char getTurn();

    void moveSmart(int cell);

    ttt_move minimax(TicTacToe ticTacToe, char curr_player) {
        char max_player = turn;
        char other_player = (curr_player == 'X') ? 'O' : 'X';
        ttt_move best, current;

        // base condition for win - lose
        if (ticTacToe.getStatus() == other_player)
        {
            best.score = ticTacToe.allPossibleMoves().size() + 1;
            if (other_player != max_player)
                best.score = -best.score;
            return best;
        }
        // base condtion for draw
        if (ticTacToe.getStatus() == TIE)
        {
            best.score = 0;
            return best;
        }

        if (curr_player == max_player)
            best.score = -1000000;
        else
            best.score = 1000000;

        vector<int> move_set = ticTacToe.allPossibleMoves();

        for (int i = 0; i < move_set.size(); i++)
        {
            boards[board_no/3][board_no%3].move(move_set[i],curr_player);
            current = minimax(ticTacToe,other_player);
            boards[board_no/3][board_no%3].setChar(' ',move_set[i]);
            boards[board_no/3][board_no%3].resetWinner();
            current.index = move_set[i];

            if (curr_player == max_player)
            {
                if (current.score > best.score)
                    best = current;
            }
            else
            {
                if (current.score < best.score)
                    best = current;
            }
        }
        return best;
    }

    void moveHuman(int cell);

    void moveRandom(int cell);

    int setUpCell(int X, int Y);
    int getBoardNo();
    void setBoardNo(int board_no);
    bool boardFinished();
    void selectNewBoard();
    Status update();
    vector<int> allPossibleMoves(); // for AI player

private:
    void initStatuses();
    void setTurn();
    int Cell;
    BoardCoordinate boardCoordinate;
    int board_no;   // current # tictactoe board
    char turn; // hold current player
    TicTacToe boards[3][3];
    Status boardStatuses[3][3];  // store the status of each tictictoe game
};
#endif //TICTACTOE_CORRECT_VERSION__NINEBOARD_H
