//#include "Coordinate.h"
#include "Board.h"
#include <string>
using namespace std;
#pragma once

class Player{
    public: 
        char myChar;

        char getChar() const { return myChar; };
        inline void setChar(const char& c) { myChar=c;}
        virtual const string name() const{return "";};
        virtual const Coordinate play(const Board& board) {};
    
};