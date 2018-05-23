#include "Coordinate.h"
#include "Board.h"
#include <string>
using namespace std;
#pragma once

class Player{
    public: 
        char myChar;

    char getChar(){ return myChar; };
    void setChar(const char c) { myChar=c;}
    virtual const string name() const;
    virtual const Coordinate play(const Board& board) = 0;
    
};