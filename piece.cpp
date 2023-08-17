#include "piece.h"
#include <array>

Piece::Piece(){
}
Piece::~Piece(){}

int Piece::getType(){
    return type;
}

bool Piece::getColor(){
    return color;
}

Square* Piece::getSquare(){
    return square;
}

void Piece::setSquare(Square* _square){
    square = _square;
}

std::array<int,2> Piece::getPos(){
        return square->getPos();
}

Pawn::Pawn(bool _color, Square* _square){
    type = 0;
    color = _color;
    square = _square;
}


void Pawn::getMoves(){

}