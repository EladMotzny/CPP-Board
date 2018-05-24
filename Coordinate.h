#pragma once
//#include <cstdint>

class Coordinate{

    private:
        unsigned int row;
        unsigned int col;
    
    public:
        Coordinate(unsigned int row, unsigned int col){
            this->row=row;
            this->col=col;
        }
        //~Coordinate();
        unsigned int getCol() const { return this->col; }
        unsigned int getRow() const { return this->row; }
        Coordinate& operator=(const Coordinate& c){
            this->row=c.getRow();
            this->col=c.getCol();
            return *this;
        }
};
