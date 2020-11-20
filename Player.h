//Nguyen Dinh Luong (StudentID: 19617187)
/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from any other student’s work or from any other source. No part of the code has been written/produced for me by another person or copied from any other source.
I hold a copy of this assignment that I can produce if the original is lost or damaged.
**************************/

#ifndef TICTACTOE_CORRECT_VERSION__PLAYER_H
#define TICTACTOE_CORRECT_VERSION__PLAYER_H
#include "iostream"
#include "NineBoard.h"
using namespace std;

class Player {
protected:
   char symbol;
public:
    Player(char Symbol) {
        symbol = Symbol;
    }

    char getSymbol() { return symbol; }

    void getMove(NineBoard board, int &cell);

};

class HumanPlayer: public Player {
public:
    HumanPlayer(char s) : Player(s) {}

    void getMove(NineBoard board, int& cell) {
        BoardCoordinate boardCoordinate;
        cout << "Player Human. Please select the position of move"<<endl;
        cout << "X coordinate: ";
        cin >> boardCoordinate.Xcoordinate;
        cout << "Y coordinate: ";
        cin >> boardCoordinate.Ycoordinate;
        if(boardCoordinate.Xcoordinate <=0 || boardCoordinate.Ycoordinate > 3) {
            cout << "Player Human. Please select the position of move"<<endl;
            cout << "X coordinate: ";
            cin >> boardCoordinate.Xcoordinate;
            cout << "Y coordinate: ";
            cin >> boardCoordinate.Ycoordinate;
        }
        while(boardCoordinate.Xcoordinate <=0 || boardCoordinate.Ycoordinate > 3)
        {
            cout << "Player Human. Please select the position of move"<<endl;
            cout << "X coordinate: ";
            cin >> boardCoordinate.Xcoordinate;
            cout << "Y coordinate: ";
            cin >> boardCoordinate.Ycoordinate;
        }
        cell = board.setUpCell(boardCoordinate.Xcoordinate, boardCoordinate.Ycoordinate);
    }
};

class RandomPlayer: public Player {
public:
    RandomPlayer(char s) : Player(s) {}

    void getMove(NineBoard board, int& cell) {
        cout << "Player Random. Please select the position of move"<<endl;
        int X = rand()%3+1;
        cout << "X coordinate: "<<X<<endl;
        int Y = rand()%3+1;
        cout << "Y coordinate: "<<Y<<endl;
        cell = board.setUpCell(X,Y);
    }
};


class AIPlayer: public Player {
public:
    AIPlayer(char s) : Player(s) {}

    void getMove(NineBoard board, int& cell) {

    }
};



#endif //TICTACTOE_CORRECT_VERSION__PLAYER_H
