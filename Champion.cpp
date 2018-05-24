/*#include "Board.h"
#include "Champion.h"
#include "DummyPlayers.h"
#include "IllegalCharException.h"
#include "Player.h"
#include "TicTacToe.h"
#include "IllegalCoordinateException.hpp"*/
#include "Champion.h"

const Coordinate Champion::play(const Board& board) {
    
    unsigned int i, j, size = board.size();
    
    if(board[{0,size-1}] == '.')
        return Coordinate{0,size-1};
    
    if(board[{size-1,0}] =='.')
        return Coordinate{size-1,0};
    
    for(i = 1; i < size-1; i++){
        if(board[{i,size-1-i}] == '.')
            return Coordinate{i,size-1-i};
    }
    
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            if(board[{i,j}] == '.')
                return Coordinate{i, j};
        }
    }
}