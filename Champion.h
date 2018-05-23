#pragma once
#include "Board.h"
#include "Coordinate.h"
#include "Player.h"


class Champion: public Player {
    //string name = "Alex Fishman & Elad Motzny";
public:
	const string name() const override { return "Alex Fishman & Elad Motzny"; }
	const Coordinate play(const Board& board) override;
};