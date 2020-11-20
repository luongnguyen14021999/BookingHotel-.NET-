//Nguyen Dinh Luong (StudentID: 19617187)
/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from any other student’s work or from any other source. No part of the code has been written/produced for me by another person or copied from any other source.
I hold a copy of this assignment that I can produce if the original is lost or damaged.
**************************/

#ifndef TICTACTOE_CORRECT_VERSION__GAME_H
#define TICTACTOE_CORRECT_VERSION__GAME_H
#include "NineBoard.h"
#include "Player.h"
class NBGame {
    NineBoard board;
    HumanPlayer humanPlayer;
    RandomPlayer randomPlayer;
public:
    NBGame(HumanPlayer humanPlayer, RandomPlayer randomPlayer)
            : humanPlayer(humanPlayer), randomPlayer(randomPlayer) {}
    void play() {
        board.displayBoards();
        BoardCoordinate boardCoordinate;
        int board_no;
        cout << "Enter the board number to start with: ";
        cin >> board_no;
        board.setBoardNo(board_no-1); // minus 1 for zero-based indexing
        int cell;
        bool playing = true;
        while(playing)
        {
            if(board.getTurn()== humanPlayer.getSymbol())
            {
                humanPlayer.getMove(board,cell);
                board.moveHuman(cell);
                cout<<endl;
            }

            if(board.getTurn()== randomPlayer.getSymbol()) {
                randomPlayer.getMove(board,cell);
                board.moveRandom(cell);
                cout<<endl;
            }
            board.displayBoards();
            int status = board.update();

            switch(status)
            {
                case X:
                    if(humanPlayer.getSymbol() == 'X') {
                        cout << "Human has won!" << endl;
                    }
                    if(randomPlayer.getSymbol() == 'X') {
                        cout << "Random has won!" << endl;
                    }
                    playing = false;
                    break;
                case O:
                    if(humanPlayer.getSymbol() == 'O') {
                        cout << "Human has won!" << endl;
                    }
                    if(randomPlayer.getSymbol() == 'O'){
                        cout << "Random has won!" << endl;
                    }
                    playing = false;
                    break;
                case TIE:
                    cout << "Game over. Tie" << endl;
                    playing = false;
                    break;
                default:
                    break;
            }
        }
    }
};
#endif //TICTACTOE_CORRECT_VERSION__GAME_H
