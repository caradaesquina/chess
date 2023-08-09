#ifndef SQUARE
#define SQUARE

#include <iostream>
#include <string>
using namespace std;

class Square{
    private:
        int collumn;
        int row;
        bool color;
    public:
        Square(int _collumn, int _row, bool _color);
        ~Square();
        int getCollumn();
        int getRow();
        bool getColor(); 
};

#endif