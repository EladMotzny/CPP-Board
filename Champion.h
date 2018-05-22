#pragma once

class Champion: public Player {
    string name = "Alex Fishman & Elad Mozny";
public:
	const string name() const override { return name; }
	const Coordinate play(const Board& board) override;
};