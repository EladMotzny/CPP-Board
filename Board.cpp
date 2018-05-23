#include "Board.h"
#include "Champion.h"
#include "DummyPlayers.h"
#include "IllegalCharException.h"
#include "Player.h"
#include "Square.h"
#include "TicTacToe.h"
#include "IllegalCoordinateException.hpp"


#include <iostream>
#include <initializer_list>
#include <cassert>
#include <stdexcept>


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


ostream& operator<<(ostream& out,const Board& b){//changed to const
    for(int i=0; i<b.getRow(); i++){
        //out << "|";
        for(int j=0; j<b.getCol(); j++){
            out << "" << b.board[i][j].getContent();// << " |";
        }
    out << endl; //<< "________________" << endl;

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

bool Board::isRow(const Board& b, const char& c){
    bool flag=false;
    bool* flagArr=new bool[b.getCol()];
    for(int i=0;i<b.getCol();i++){//initializing the array
        flagArr[i]=true;
    }
    for(int i=0;i<b.getCol();i++){//the actual check
        for(int j=0; j<b.getRow();j++){
            if(b.board[i][j].getContent()!=c){
                flagArr[i]=false;
            }
        }
    }
    for(int i=0;i<b.getCol();i++){//checking to see if there's a win
        if(flagArr[i]==true){
            flag=true;
        }
    }
    delete[] flagArr;
    return flag;
}

bool Board::isLine(const Board& b, const char& c){
    bool flag=false;
    bool* flagArr=new bool[b.getCol()];
    for(int i=0;i<b.getCol();i++){//initializing the array
        flagArr[i]=true;
    }
    for(int i=0;i<b.getCol();i++){//the actual check
        for(int j=0; j<b.getRow();j++){//dont need to change getRow and getCol because its the same number
            if(b.board[j][i].getContent()!=c){
                flagArr[i]=false;
            }
        }
    }
    for(int i=0;i<b.getCol();i++){//checking to see if there's a win
        if(flagArr[i]==true){
            flag=true;
        }
    }
    delete[] flagArr;
    return flag;
}

bool Board::isDiagonalLeft(const Board& b, const char& c){//top left to bottom
    bool flag=true;
    for(int i=0;i<b.getCol();i++){
        if(b.board[i][i].getContent()!=c){
            flag=false;
        }
    }
    return flag;
}

bool Board::isDiagonalRight(const Board& b, const char& c){//top right to bottom
    bool flag=true;
    int i=0;
    int j=b.getCol()-1;//CHANGE TO b.getrow-1 or something
    for(i=0;i<b.getCol();i++){
        if(b.board[i][j].getContent()!=c){
            flag=false;
        }
        j--;
    }
    return flag;

}

bool Board::isWin(const Board& b, const char& c){
    if((isRow(b, c)==true)||(isLine(b,c)==true)||(isDiagonalLeft(b,c)==true)||(isDiagonalRight(b,c)==true)){
        return true;
    }
    else{
        return false;
    }
}
/*
bool Board::isFull(const Board& b){
    
}*/


/*
char Board::operator=(initializer_list<int> coordinate){
    int *tmpArr=new int[2];
    copy(coordinate.begin(), coordinate.end(), tmpArr);
    int tmpX=tmpArr[0];
    int tmpY=tmpArr[1];
    delete[] tmpArr;
    return this->board[tmpX][tmpY].getContent();
}
*/



 