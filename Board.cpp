#include <iostream>
//#include "Square.h"
#include "Board.h"
#include "IllegalCharException.h"
#include <initializer_list>
#include <cassert>
#include <stdexcept>
#include "IllegalCoordinateException.hpp"


using namespace std;

Board::Board(){
    Board{4};
    // row = 4;
    // col = 4;
    // board = new Square*[col];
    // for (int i = 0; i < col; i++)
    // {
    //     board[i] = new Square('.');
    // }
    // for(int i=0; i<row; i++){
    //     for(int j=0; j<col; j++){
    //         board[i][j].setContent('.');
    //     }    
    // }
}

Board::Board(int n){
    //cout << "called c'tor" << endl;
    row = n;
    col = n;
    board = new Square*[col];
    for (int i = 0; i < col; i++)
    {
        board[i] = new Square[row]; //new Square('.');
    }
    for(int i=0; i<row; i++){
        for(int j=1; j<col; j++){
            board[i][j].setContent('.');
        }    
    }
}

Board::Board(const Board& other){
    //cout << "copy c'tor" << endl;
    row = other.row;
    col = other.col;
    board = new Square*[col];
    for (int i = 0; i < col; i++)
    {
        board[i] = new Square[row]; //new Square('.');
    }
    for(int i=0; i<other.row; i++){
        for(int j=0; j<other.col; j++){
                this->board[i][j] = other.board[i][j];
        }
    }
}

Board::~Board() //Destructor
{ 
    for (int i = 0; i < this->row; i++){
        delete [] board[i];
    }
    //sagi hamudi
    delete [] board;
} 


ostream& operator<<(ostream& out, Board& b){
    for(int i=0; i<b.getRow(); i++){
        //out << "|";
        for(int j=0; j<b.getCol(); j++){
            out << "" << b.board[i][j].getContent();// << " |";
        }
    out << endl << "________________" << endl;

    }
    return out;
}

Square& Board::operator[](initializer_list<int> coordinate){
    int *m_array = new int[2];
    copy(coordinate.begin(), coordinate.end(), m_array);
    if(sizeof(m_array) != sizeof(int)*2 || m_array[0]>=this->getRow() || m_array[1]>=this->getCol())
        throw IllegalCoordinateException(coordinate);
        //throw invalid_argument("Wrong cell input!");
    
    int x = m_array[0];
    int y = m_array[1];
    delete []m_array;
    return this->board[x][y];
}


void Board::operator=(const char c){
    if(c=='.'){
        for(int i=0; i<this->row; i++){
            for(int j=0; j<this->col; j++){
                    this->board[i][j] = c;
            }
        }
    }
    else{
        throw IllegalCharException(c);
    }
}

void Board::operator=(const Board& b){
    for(int i=0; i<b.row; i++){
        for(int j=0; j<b.col; j++){
                this->board[i][j] = b.board[i][j];
        }
    }
}

/*
//takes the first char of every row and checks if every other char in that row is the same
bool Board::isRow(const Board b){
    char check;
    bool ans=true;//change to true?
    int i,j;
    while(i<b.col){
        check=b.board[i][0].getContent();
        while(j<b.row){
            if(b.board[i][j].getContent()!=check){
                ans=false;
            }
            j++;
        }
        if(ans==true){
            return true;
        }
        i++;
    }
    return false;
}

bool Board::isLine(const Board b){}


bool Board::isDiagonalLeft(const Board b){}

bool Board::isDiagonalRight(const Board b){}


*/


 