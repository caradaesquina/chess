#include "square.h"
#include <vector>
#include <string>

Square::Square(){}
Square::Square(std::array<int,2> _pos, bool _color){
    pos = _pos;
    color = _color;
}

Square::~Square(){}

std::array<int,2> Square::getPos(){return pos;}
bool Square::getColor(){return color;}