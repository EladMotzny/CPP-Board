#include "Player.h"
#include "Coordinate.h"
#include <string>



class Champion: public Player {
    //string name = "Alex Fishman & Elad Motzny";
public:
	const string name() const override { return "Alex Fishman & Elad Motzny"; }
	const Coordinate play(const Board& board) override;
};