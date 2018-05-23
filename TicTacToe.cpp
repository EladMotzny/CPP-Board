#include "Board.h"
#include "Champion.h"
#include "DummyPlayers.h"
#include "IllegalCharException.h"
#include "Player.h"
#include "Square.h"
#include "TicTacToe.h"
#include "Coordinate.h"
#include "IllegalCoordinateException.hpp"



void TicTacToe::play(const Player& playerX,const Player& playerO){
        
    playerX.setChar('X');
    playerO.setChar('O');
    winner = &playerO;
    
    // _board = Symbol::P; //reset board
    bool turn = true;
    int i, numOfSquares = size;
    
    for(i = 0; i < numOfSquares && !has_won(playerX, playerO); i++){
        if(turn){
            try{
                // _board[xPlayer.play(_board)] = xPlayer.getChar(); //need to check if it's a point
                Coordinate c = playerX.play(game);
                if(game[c] == '.'){
                    game[c] = playerX.getChar();
                }
                else
                    throw IllegalCoordinateException(c);
                } 
                catch(const IllegalCoordinateException ex){
                    break;
                } 
                catch(const string& ex){
                    break;
                }
            turn = false;
        }
        else{
            try{
                // _board[oPlayer.play(_board)] = oPlayer.getChar();
                Coordinate c = playerO.play(game);
                if(game[c] == '.'){
                    game[c] = playerO.getChar();
                } 
                else
                    throw IllegalCoordinateException(c);
            }
            catch(const IllegalCoordinateException ex){
                winner = &playerX;
                break;
            }   
            catch(const string& ex){
                winner = &playerX;
                break;
            }
            turn = true;
        }
    }
}

bool has_won(Player& playerX, Player& playerO){

    int i, j;
    int size = game.size();
    char c = game[{0,size-1}];
    
    //left diagonal
    if(c != '.'){
        for(i = 1; i < size; i++){
            if(game[{i, size-1-i}] != c)
                break;
            if(i == size-1){
                if(c == playerX.getChar())
                    winPlayer = &playerX;
                return true;
            }
        }
    }
    
    c = game[{0,0}];
    //right diagonal
    if(c != '.'){
        for(i = 1; i < size; i++){
            if(game[{i, i}] != c)
                break;
            if(i == size-1){
                if(c == playerX.getChar())
                    winPlayer = &playerX;
                return true;
            }
        }
    }
    
    //columns
    for(j = 0; j<size; j++){
        c = game[{0,j}];
        if(c != '.'){
            for(i = 1; i<size; i++){
                if(game[{i, j}] != c)
                    break;
                if(i == size-1){
                    if(playerX.getChar() == c)
                        winPlayer = &playerX;
                    return true;
                }
            }
        }
    }
    
    //rows
    for(i = 0; i<size; i++){
        c = game[{i,0}];
        if(c != '.'){
            for(j = 1; j<size; j++){
                if(game[{i, j}] != c)
                    break;
                if(j == size-1){
                    if(playerX.getChar() == c)
                        winPlayer = &playerX;
                    return true;
                }
            }
        }
    }
    
return false;
}