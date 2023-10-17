#include "piece.h"


Piece::Piece(bool c, Square* initSquare){
    color = c;
    originalSquare = initSquare;
    actualSquare = originalSquare;
    moved = false;
}

Piece::~Piece(){
    for (auto &mv : moves){
        delete(mv);
    }
}

bool Piece::getColor(){
    return color;
}

int Piece::getCode(){
    return code;
}

int Piece::getPieceType(){
    return type;
}

Square* Piece::getActualSquare(){
    return actualSquare;
}

Square* Piece::getOriginalSquare(){
    return originalSquare;
}

bool Piece::hasMoved(){
    return moved;
}

std::vector<PieceMove*> Piece::getMoves(){
    return moves;
}

Pawn::Pawn(bool c, Square* sq): Piece(c, sq){
    type = PAWN;
    generateMoves();
}

Pawn::~Pawn(){
}

void Pawn::generateMoves(){
    moves = {
        new PieceMove(MOVEMENT, {0,1}),
    };
}