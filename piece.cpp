#include "piece.h"
#include <array>
#include <iostream>

Piece::Piece(){
}
Piece::~Piece(){
    for (auto& i : allPieceMoves){
        delete(i);
        std::cout << "Deleting move..." << std::endl;
    }
}

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
    allPieceMoves = {
        new PieceMove(movement, {0,1}), // regular forward pawn movement
        new PieceMove(firstMovement, {0,2}), //move from pawn first position
        new PieceMove(capture, {1,1}), new PieceMove(capture, {1,-1}), //pawn captures
        new PieceMove(promotion, {0,0}), //promotion, doesnt alter pawn's current location
        new PieceMove(enPassant, {1,1}), new PieceMove(enPassant, {1,-1}) //special pawn move: https://en.wikipedia.org/wiki/En_passant
    };

}

std::vector<PieceMove*> Pawn::getMoves(){
    return allPieceMoves;
}