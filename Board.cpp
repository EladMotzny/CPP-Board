// #include "Board.h"
#include "Square.cpp"
#include <iostream>

Board::Board(int n){
    Square board[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            board[i][j] = Square(".");
        }
    }
}

friend ostream& Board::operator<<(ostream& stream, const Board board){
    int n=board.getSize();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // stream << board[i].getContent();
        }
        // stream << "\n"
    }
    return stream;
}