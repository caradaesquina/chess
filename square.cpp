#include "square.h"
#include <string>

Square::Square(int _collumn, int _row, bool _color){
    collumn = _collumn;
    row = _row;
    color = _color;
}

Square::~Square(){
    
}

int Square::getCollumn(){
    return collumn;
}

int Square::getRow(){
    return row;
}

bool Square::getColor(){
    return color;
}

