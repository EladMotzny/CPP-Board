//#pragma once
//#include "Board.h"
//#include "Champion.h"
//#include "DummyPlayers.h"
//#include "IllegalCharException.h"
#include "Player.h"
#include "Coordinate.h"
#include <string>
//#include "TicTacToe.h"
//#include "IllegalCoordinateException.hpp"


class Champion: public Player {
    //string name = "Alex Fishman & Elad Motzny";
public:
	const string name() const override { return "Alex Fishman & Elad Motzny"; }
	const Coordinate play(const Board& board) override;
};