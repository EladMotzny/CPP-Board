#include <iostream>
#include <initializer_list>
#include <cassert>
#include <exception>
#include <string>
#include <sstream>
#pragma once
using namespace std;


class IllegalCoordinateException: public exception{
    protected:
        int *corArr=new int[2];
        int tmpCol;
        int tmpRow;
    public:
        IllegalCoordinateException(initializer_list<int> coordinate){
            copy(coordinate.begin(),coordinate.end(),corArr);
            tmpRow=corArr[0];
            tmpCol=corArr[1];
            delete[] corArr;
        }

    virtual const string theCoordinate() const throw(){
       // return this->getTmpRow()+","+this->getTmpCol();
       ostringstream os;
       //os << this->getTmpRow() << "," << this->getTmpCol();
       os << tmpRow << "," << tmpCol;
       return os.str(); 
    }


};