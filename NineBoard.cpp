//Nguyen Dinh Luong (StudentID: 19617187)
/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from any other student’s work or from any other source. No part of the code has been written/produced for me by another person or copied from any other source.
I hold a copy of this assignment that I can produce if the original is lost or damaged.
**************************/

#include <iostream>
#include <iomanip>
#include "NineBoard.h"
using namespace std;

NineBoard::NineBoard()
{
    turn = 'X';
    initStatuses();
}

void NineBoard::initStatuses()
{
    /*
     * Initialise board statuses to NONE
     */
    for(int x = 0; x < 3; x++)
        for(int y = 0; y < 3; y++)
            boardStatuses[x][y] = NONE;
}

int NineBoard:: setUpCell(int X, int Y) {
    if((X==1 && Y==1) || (X==1 && Y==2) || (X==1 && Y==3)) {
        return X+Y - 1;
    } else if((X==2 && Y==1) || (X==2 && Y==2) || (X==2 && Y==3)) {
        return X+ Y + 1;
    } else {
        return X*2 + Y;
    }
}

char NineBoard::getTurn()
{
    if(turn == 'X') {
        return 'X';
    } else {
        return 'O';
    }
}

void NineBoard::setTurn()
{
    if(turn == 'X') {
        turn = 'O';
    } else {
        turn = 'X';
    }
}

int NineBoard::getBoardNo()
{
    return board_no;
}

void NineBoard::setBoardNo(int board_No)
{
    board_no = board_No;
}

bool NineBoard::boardFinished()
{
    if(boardStatuses[board_no/3][board_no%3] != NONE)
        return true;
    return false;
}

void NineBoard::selectNewBoard()
{
    cout << "The game on the next board is finished, " << getTurn() << " select next board: ";
    cin >> board_no;
    board_no -= 1;
    if(boardFinished())
        selectNewBoard();
}

void NineBoard::moveHuman(int cell)
{
    Cell = cell;
    cout << "Board no: " << board_no+1 << endl;
    // convert 1d index to 2d
    if(boards[board_no/3][board_no%3].move(cell, turn)) {
        // minus 1 for zero indexing and convert 2d index to 1d :D
        board_no = cell - 1;
    } else {
        // chosen cell is already occupied
        cout << "Position already occupied. Try again." << endl;
        cout << "X coordinate: ";
        cin >> boardCoordinate.Xcoordinate;
        cout << "Y coordinate: ";
        cin >> boardCoordinate.Ycoordinate;
        while (boardCoordinate.Xcoordinate <=0 || boardCoordinate.Ycoordinate > 3) {
            cout << "X coordinate: ";
            cin >> boardCoordinate.Xcoordinate;
            cout << "Y coordinate: ";
            cin >> boardCoordinate.Ycoordinate;
        }
        cell = setUpCell(boardCoordinate.Xcoordinate,boardCoordinate.Ycoordinate);
        moveHuman(cell);  // call the function again with new parameters
    }
}

void NineBoard::moveRandom(int cell)
{
    Cell = cell;
    cout << "Board no: " << board_no+1 << endl;
    // convert 1d index to 2d
    if(boards[board_no/3][board_no%3].move(cell, turn)) {
        // minus 1 for zero indexing and convert 2d index to 1d :D
        board_no = cell - 1;
    } else{
        // chosen cell is already occupied
        cout << "Position already occupied. Try again." << endl;
        int X = rand()%3+1;
        cout << "X coordinate: "<<X<<endl;
        int Y = rand()%3+1;
        cout << "Y coordinate: "<<Y;
        cout<<endl;
        cell = setUpCell(X,Y);
        moveRandom(cell);  // call the function again with new parameters
    }
}



void NineBoard::displayBoards()
{
    for (int w = 0; w < 3; w++) {
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                for (int z = 0; z < 3; z++) {

                    if(Cell == 1) {
                        if (w == 0 && x == 0 && y == 0 && z == 0) {
                            cout << "   *  *  *  *  *";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << endl;
                        }
                        if (w == 1 && x == 0 && y == 0 && z==0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout<<endl;
                        }
                        if (w == 2 && x == 0 && y == 0 && z==0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout<<endl;
                        }
                    } else if(Cell==2) {
                        if (w == 0 && x == 0 && y == 0 && z == 0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   *  *  *  *  *";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << endl;
                        }
                        if (w == 1 && x == 0 && y == 0 && z==0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout<<endl;
                        }
                        if (w == 2 && x == 0 && y == 0 && z==0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout<<endl;
                        }
                    } else if(Cell == 3) {
                        if (w == 0 && x == 0 && y == 0 && z == 0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   *  *  *  *  *";
                            cout << "   ";
                            cout << endl;
                        }
                        if (w == 1 && x == 0 && y == 0 && z==0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout<<endl;
                        }
                        if (w == 2 && x == 0 && y == 0 && z==0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout<<endl;
                        }
                    } else if(Cell==4) {
                        if (w == 0 && x == 0 && y == 0 && z == 0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << endl;
                        }
                        if (w == 1 && x == 0 && y == 0 && z==0) {
                            cout << "   *  *  *  *  *";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout<<endl;
                        }
                        if (w == 2 && x == 0 && y == 0 && z==0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout<<endl;
                        }
                    } else if(Cell==5) {
                        if (w == 0 && x == 0 && y == 0 && z == 0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << endl;
                        }
                        if (w == 1 && x == 0 && y == 0 && z==0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   *  *  *  *  *";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout<<endl;
                        }
                        if (w == 2 && x == 0 && y == 0 && z==0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout<<endl;
                        }
                    } else if(Cell == 6) {
                        if (w == 0 && x == 0 && y == 0 && z == 0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << endl;
                        }
                        if (w == 1 && x == 0 && y == 0 && z==0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   *  *  *  *  *";
                            cout << "   ";
                            cout<<endl;
                        }
                        if (w == 2 && x == 0 && y == 0 && z==0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout<<endl;
                        }
                    } else if(Cell == 7) {
                        if (w == 0 && x == 0 && y == 0 && z == 0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << endl;
                        }
                        if (w == 1 && x == 0 && y == 0 && z==0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout<<endl;
                        }
                        if (w == 2 && x == 0 && y == 0 && z==0) {
                            cout << "   *  *  *  *  *";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout<<endl;
                        }
                    } else if(Cell == 8) {
                        if (w == 0 && x == 0 && y == 0 && z == 0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << endl;
                        }
                        if (w == 1 && x == 0 && y == 0 && z==0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout<<endl;
                        }
                        if (w == 2 && x == 0 && y == 0 && z==0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   *  *  *  *  *";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout<<endl;
                        }
                    } else if(Cell == 9) {
                        if (w == 0 && x == 0 && y == 0 && z == 0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << endl;
                        }
                        if (w == 1 && x == 0 && y == 0 && z==0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout<<endl;
                        }
                        if (w == 2 && x == 0 && y == 0 && z==0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   *  *  *  *  *";
                            cout << "   ";
                            cout<<endl;
                        }
                    } else  {
                        if (w == 0 && x == 0 && y == 0 && z == 0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << endl;
                        }
                        if (w == 1 && x == 0 && y == 0 && z==0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout<<endl;
                        }
                        if (w == 2 && x == 0 && y == 0 && z==0) {
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout << "   -  -  -  -  -";
                            cout << "   ";
                            cout<<endl;
                        }
                    }

                    if((y==1 && x==0 && z==0) || (y==1 && x==1 && z==0) || (y==1 && x==2 && z==0) || (y==2 && x==0 && z==0) || (y==2 && x==1 && z==0) || (y==2 && x==2 && z==0)) {
                        if((Cell==1 && y==1 && w==0) || (Cell==4 && y==1 && w==1) || (Cell==7 && y==1 && w==2) ) {
                            cout<<"*";
                        } else if((Cell==2 && y==2 && w==0) || (Cell==5 && y==2 && w==1) || (Cell==8 && y==2 && w==2) ) {
                            cout <<"*";
                        }  else {
                            cout <<"|";
                        }
                        if((Cell==2 && y==1 && w==0 && z==0) || (Cell==5 && y==1 && w==1 && z==0) || (Cell==8 && y==1 && w==2 && z==0)) {
                            cout << "*"<<setw(3);
                            cout <<boards[w][y].board[x][z]<<setw(3);
                        } else if((Cell==3 && y==2 && w==0 && z==0) || (Cell==6 && y==2 && w==1 && z==0) || (Cell==9 && y==2 && w==2 && z==0)) {
                            cout << "*"<<setw(3);
                            cout <<boards[w][y].board[x][z]<<setw(3);
                        } else {
                            cout << "|"<<setw(3);
                            cout <<boards[w][y].board[x][z]<<setw(3);
                        }
                    } else {
                        if((Cell==1 && y==0 && w==0 && z==0) || (Cell==4 && y==0 && w==1 && z==0) || (Cell==7 && y==0 && w==2 && z==0)) {
                            cout << "*"<<setw(3);
                            cout <<boards[w][y].board[x][z]<<setw(3);
                        } else {
                            cout << "|"<<setw(3);
                            cout <<boards[w][y].board[x][z]<<setw(3);
                        }
                    }
                }
            }

            if((Cell==3 && w==0) || (Cell==6 && w==1) || (Cell==9 && w==2)) {
                cout << "*";
            } else {
                cout<<"|";
            }
            cout<<endl;

            if(x != 2) {
                if(Cell==1 && w==0) {
                    cout << "*  -     -     -  *";
                    cout << "|  -     -     -  |";
                    cout << "|  -     -     -  |";
                    cout<<endl;
                } else if(Cell==2 && w==0) {
                    cout << "|  -     -     -  |";
                    cout << "*  -     -     -  *";
                    cout << "|  -     -     -  |";
                    cout<<endl;
                } else if(Cell==3 && w==0) {
                    cout << "|  -     -     -  |";
                    cout << "|  -     -     -  |";
                    cout << "*  -     -     -  *";
                    cout<<endl;
                } else if(Cell==4 && w==1) {
                    cout << "*  -     -     -  *";
                    cout << "|  -     -     -  |";
                    cout << "|  -     -     -  |";
                    cout<<endl;
                }
                else if(Cell==5 && w==1) {
                    cout << "|  -     -     -  |";
                    cout << "*  -     -     -  *";
                    cout << "|  -     -     -  |";
                    cout<<endl;
                } else if(Cell==6 && w==1) {
                    cout << "|  -     -     -  |";
                    cout << "|  -     -     -  |";
                    cout << "*  -     -     -  *";
                    cout<<endl;
                } else if(Cell==7 && w==2) {
                    cout << "*  -     -     -  *";
                    cout << "|  -     -     -  |";
                    cout << "|  -     -     -  |";
                    cout<<endl;
                }
                else if(Cell==8 && w==2) {
                    cout << "|  -     -     -  |";
                    cout << "*  -     -     -  *";
                    cout << "|  -     -     -  |";
                    cout<<endl;
                } else if(Cell==9 && w==2) {
                    cout << "|  -     -     -  |";
                    cout << "|  -     -     -  |";
                    cout << "*  -     -     -  *";
                    cout<<endl;
                } else {
                    cout << "|  -     -     -  |";
                    cout << "|  -     -     -  |";
                    cout << "|  -     -     -  |";
                    cout<<endl;
                }
            } else {
                if((Cell==1 && w==0 && x==2) || (Cell==4 && w==1 && x==2) || (Cell==7 && w==2 && x==2) ){
                    cout << "   *  *  *  *  *";
                    cout << "   ";
                    cout << "   -  -  -  -  -";
                    cout << "   ";
                    cout << "   -  -  -  -  -";
                    cout << "   ";
                } else if((Cell==2 && w==0 && x==2) || (Cell==5 && w==1 && x==2) || (Cell==8 && w==2 && x==2)) {
                    cout << "   -  -  -  -  -";
                    cout << "   ";
                    cout << "   *  *  *  *  *";
                    cout << "   ";
                    cout << "   -  -  -  -  -";
                    cout << "   ";
                } else if((Cell==3 && w==0 && x==2) || (Cell==6 && w==1 && x==2) || (Cell==9 && w==2 && x==2)) {
                    cout << "   -  -  -  -  -";
                    cout << "   ";
                    cout << "   -  -  -  -  -";
                    cout << "   ";
                    cout << "   *  *  *  *  *";
                    cout << "   ";
                } else {
                    cout << "   -  -  -  -  -";
                    cout << "   ";
                    cout << "   -  -  -  -  -";
                    cout << "   ";
                    cout << "   -  -  -  -  -";
                    cout << "   ";
                }
            }
        }
        cout << endl;
    }
}

Status NineBoard::update()
{
    for(int x = 0; x < 3; x++) {
        for(int y = 0; y < 3; y++) {
            boardStatuses[x][y] = boards[x][y].update();
        }
    }

    bool tie = true;
    /* check for a tie */
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(boardStatuses[i][j] == NONE)
                tie = false;

    if(tie)
        return TIE;
    /* check for a win */
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(boardStatuses[i][j] != NONE)
                if(getTurn() == 'X') {
                    return X;
                } else {
                    return O;
                }

    setTurn(); // change player
    return NONE;
}
