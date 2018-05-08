#include <iostream>
#pragma once
using namespace std;

class Square{
        char content;
        public:
            Square(char c);
            Square();
            ~Square();
            operator char()const{
                return this->getContent();
            } 
            void operator=(const char c);
            char getContent() const{
                return this->content;
            }
            void setContent(char c){
                this->content = c;
            }
};