#include <iostream>
using namespace std;

class Board
{
    int n; //Number of rows+columns
    public:
        Board(int n);
        ~Board(){}
        friend ostream& operator<<(ostream& stream, const Board board);
        int getSize(){
            return this->n;
        }
};

// int Board::getSize(){
//     return this->n;
// }