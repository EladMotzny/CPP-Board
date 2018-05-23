#include "Board.h"
#include "Champion.h"
#include "DummyPlayers.h"
#include "IllegalCharException.h"
#include "Player.h"
#include "Square.h"
#include "TicTacToe.h"
#include "Coordinate.h"
#include "IllegalCoordinateException.hpp"


using namespace std;

Square::Square(){
    // cout << "Square default c-tor"<< endl;
     content = '.';  // initialize array to all .
} 

Square::~Square(){}

Square::Square(char c){
     content = c;  // initialize array to all c (X or O)
}

void Square::operator=(const char c){
    if(c=='.' || c=='X' || c=='O')
        this->content = c;
    else
        throw  IllegalCharException(c);
} 