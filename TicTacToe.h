#include <iostream>
#include "Board.h"
#include "DummyPlayers.h"
#include "Player.h"
using namespace std;
#pragma once

class TicTacToe{
    int size;

    public:
        TicTacToe(int size);
        void play(const XYPlayer& firstX, const YXPlayer& second);
}