#pragma once
#include "Board.h"
#include "Player.h"



#include <iostream>
using namespace std;


class TicTacToe{
    int size;
    Board* game = new Board();
    Player *winPlayer;

    public:
        TicTacToe(){size = 0;}
		TicTacToe(int size){size = size; game = new Board(size);}
		void play(const Player& first,const Player& second);	
		const Board& board ()const{return *game;};
        const Player& winner() const { return *winPlayer; }
        bool has_won(Player& playerX, Player& playerO);
};