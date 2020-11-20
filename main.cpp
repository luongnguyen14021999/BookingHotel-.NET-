//Nguyen Dinh Luong (StudentID: 19617187)
/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from any other student’s work or from any other source. No part of the code has been written/produced for me by another person or copied from any other source.
I hold a copy of this assignment that I can produce if the original is lost or damaged.
**************************/

#include <iostream>
#include "Game.h"
using namespace std;

int main()
{
    srand((int) time(0));
    char humanSymbol;
    char randomSymbol;
    char AISymbol;
    while(true) {
        cout<<"Which symbol do you want to choose (X or O, X go first)?: ";
        cin>>humanSymbol;
        if(humanSymbol == 'X' || humanSymbol == 'O') {
            break;
        }
    }
    if(humanSymbol== 'X') {
        randomSymbol = 'O';
    } else {
        randomSymbol = 'X';
    }
    if(humanSymbol== 'X') {
        AISymbol = 'O';
    } else {
        AISymbol = 'X';
    }
    HumanPlayer humanPlayer = HumanPlayer(humanSymbol);
    RandomPlayer  randomPlayer = RandomPlayer(randomSymbol);
    AIPlayer computerAi = AIPlayer(AISymbol);
    NBGame nbGame(humanPlayer,randomPlayer);
    nbGame.play();
}


