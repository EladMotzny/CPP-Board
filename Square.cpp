#include <iostream>

class Square{
    char content;
    public:
        Square(char state){
            this->content = state;
        }
        ~Square(){}
        char getContent(){
            return this->content;
        }
};

// Square::Square(char state){
//     this->content = state;
// }

// char Square::getContent(){
//     return this->content;
// }