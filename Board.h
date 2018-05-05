#include "Square.h"
#pragma once

class Board{
    int row;
    int col;
    Square** board;
    public:
        Board();
        Board(int n);
        ~Board();
        friend ostream& operator<<(ostream& out, Board b);
        Square& operator[](initializer_list<int> coordinate);
        
        void operator=(const Board b);
        void operator=(const char c);
        int getRow(){
            return this->row;
        }
        int getCol(){
            return this->col;
        }
        void printBoard(){
            for(int i=0; i<row; i++){
                cout << "|";
                for(int j=0; j<col; j++){
                    cout << " " << board[i][j].getContent() << " |";
                }
                cout << endl << "________________" << endl;

            }
        }
};