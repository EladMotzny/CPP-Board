#include "Coordinate.h"

class Player{
    virtual const string name() const;
    virtual const Coordinate play(const Board& board);
    protected: 
        char myChar;
};