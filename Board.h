#include <iostream>
using namespace std;

class Board
{
    int n; //Number of rows+columns
    public:
        Board(int n);
        ostream& operator<<(ostream& stream, const Board board);
        int getSize();
};

Board::Board(int n){
    this->n=n;
}

int Board::getSize(){
    return this->n;
}