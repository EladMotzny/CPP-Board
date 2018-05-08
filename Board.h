#include "Square.h"
//#pragma once

class Board{
    int row;
    int col;
    Square** board;
    public:
        Board();
        Board(int n);
        Board(const Board& other);
        ~Board();
        friend ostream& operator<<(ostream& out,const Board& b);
        Square& operator[](initializer_list<int> coordinate);
        /*  bool isRow(const Board b);//Checks to see if there is a row win 
        bool isLine(const Board b);//Checks to see if there is a line win
        bool isDiagonalLeft(const Board b);//checks to see if there is a diagonal win
        bool isDiagonalRight(const Board b);//checks to see if there is a diagonal win   */
        
        void operator=(const Board& b);
        void operator=(const char c);
        /*ELAD ADDED OPERATOR NEED TO TEST*/
        //char operator=(initializer_list<int> coordinate);
        int getRow() const{
            return this->row;
        }
        int getCol() const{
            return this->col;
        }
        void printBoard() const{
            for(int i=0; i<row; i++){
                cout << "|";
                for(int j=0; j<col; j++){
                    cout << " " << board[i][j].getContent() << " |";
                }
                cout << endl << "________________" << endl;

            }
        }
};