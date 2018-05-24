#include "Player.h"
#include "IllegalCoordinateException.hpp"
#include "IllegalCharException.h"
#include <iostream>
using namespace std;


class TicTacToe{
    public:
        //int size;
        //Board* game = new Board();
        Board game;
        Player *winPlayer;

        //TicTacToe(){size = 0;}
		//TicTacToe(int size){size = size; game = new Board(size);}
        TicTacToe(int size):game(size){}
        ~TicTacToe(){}
		void play(Player& first, Player& second);	
		//const Board& board ()const{return *game;};
        const Board& board ()const{return game;};
        const Player& winner() const { return *winPlayer; }
};