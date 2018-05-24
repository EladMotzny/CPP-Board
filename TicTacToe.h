/*#pragma once
#include "Board.h"
#include "Champion.h"
#include "DummyPlayers.h"
#include "IllegalCharException.h"
#include "Player.h"
#include "Square.h"
#include "TicTacToe.h"
#include "Coordinate.h"
#include "IllegalCoordinateException.hpp"*/
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
		void play(Player& first, Player& second);	
		//const Board& board ()const{return *game;};
        const Board& board ()const{return game;};
        const Player& winner() const { return *winPlayer; }
        //bool has_won(Player& playerX, Player& playerO);
};