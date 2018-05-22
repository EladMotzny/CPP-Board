#pragma once

class Coordinate
{
    uint row;
    uint col;
    public:
        Coordinate();
        Coordinate(const Coordinate &c);
        Coordinate(uint r, uint c);
        ~Coordinate(){}
        int getRow(){
                return row;
        }
        int getCol(){
                return col;
        }
};

Coordinate::Coordinate(const Coordinate &c){

    this->row = c.row;
    this->col = c.col;
}

Coordinate::Coordinate(uint r, uint c){
    this->row = r;
    this->col = c;
}