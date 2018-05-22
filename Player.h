#include "Coordinate.h"
#include "Board.h"
#include <string>
using namespace std;
#pragma once

class Player{
    virtual const string name() const;
    virtual const Coordinate play(const Board& board);
    protected: 
        char myChar;
};