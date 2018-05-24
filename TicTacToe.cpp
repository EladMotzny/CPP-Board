#include "TicTacToe.h"


/*the game itself
-declare a player flag to know who's turn this is, if the game is over (someone won) V
-while loop, exit when board is full OR when gameWin flag is true V MIGHT WANT TO CHANGE ISFULL TO NOT GET A BOARD BUT TO USE THIS-> INSTEAD
-if(player=='X') => turn for the first player X
else => player O turn
-every time a player wants to make a move check exceptions
also check if there is already something inside the coordinate
-after each turn, check with isWin and if there is change the gameWin flag to true and according to playerTurn, change the winner and print the name
 */
void TicTacToe::play(Player& firstX, Player& secondO){
    bool gameWin=false;
    char playerTurn='X';
    firstX.setChar('X');
    secondO.setChar('O');
    Coordinate c(0,0);//the coordinate we use to check
    while((gameWin==false) && (game.isFull(this->board())==false)){
        if(playerTurn=='X'){//first player turn
            /*
            what to do for the checks:
            -create a Coordinate c and do c=player.play
            -for the first check just do an if to see if there's something inside the panel
            -for the other checks use try and catch 
            */
            c = firstX.play(this->board());//gets the coordinate that the first player wants to play at
            //checks to see if the panel is already taken
            int i=c.getRow();
            int j=c.getCol();
            if(game.board[i][j].getContent()!='.'){//panel taken, ends game, O wins
                gameWin=true;
                *winPlayer=secondO;
            }
            else{//other checks
                //checks for illegal char
                try{
                    int i=c.getRow();
                    int j=c.getCol();
                    game[{i,j}]='X';
                }
                catch(const IllegalCharException& ex){
                    cout << "Illegal char!" << endl;
                    *winPlayer=secondO;
                    gameWin=true;
                }
                //checks for illegal coordinate
                try{
                    int i=c.getRow();
                    int j=c.getCol();
                    game[{i,j}]='X';
                }
                catch(const IllegalCoordinateException& ex){
                    cout << "Illegal coordinate!" << endl;
                    *winPlayer=secondO;
                    gameWin=true;
                }
            }
            //now to see if there is a win
            if(game.isWin(game,'X')==true){//there is a win
                *winPlayer=firstX;
                gameWin=true;
            }
            playerTurn='O';
        }
        else{//second player turn
            c = Coordinate(secondO.play(game));//gets the coordinate that the first player wants to play at
            //checks to see if the panel is already taken
            int i=c.getRow();
            int j=c.getCol();
            if(game.board[i][j].getContent()!='.'){//panel taken, ends game, O wins
                gameWin=true;
                *winPlayer=firstX;
            }
            else{//other checks
                //checks for illegal char
                try{
                    int i=c.getRow();
                    int j=c.getCol();
                    game[{i,j}]='O';
                }
                catch(const IllegalCharException& ex){
                    cout << "Illegal char!" << endl;
                    *winPlayer=firstX;
                    gameWin=true;
                }
                //checks for illegal coordinate
                try{
                    int i=c.getRow();
                    int j=c.getCol();
                    game[{i,j}]='O';
                }
                catch(const IllegalCoordinateException& ex){
                    cout << "Illegal coordinate!" << endl;
                    *winPlayer=firstX;
                    gameWin=true;
                }
            }
            //now to see if there is a win
            if(game.isWin(game,'O')==true){//there is a win
                *winPlayer=secondO;
                gameWin=true;
            }
            playerTurn='X';
        }
    }
    //out of the while loop, check for a tie
    if((gameWin==false) && (game.isFull(game)==true)){
        *winPlayer=secondO;
    }
}

