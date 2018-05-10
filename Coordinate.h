class Coordinate
{
    int row;
    int col;
    public:
        Coordinate();
        Coordinate(const Coordinate &c);
        Coordinate(int r, int c);
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

Coordinate::Coordinate(int r, int c){
    this->row = r;
    this->col = c;
}