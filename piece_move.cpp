#include "piece_move.h"

#include <array>

PieceMove::PieceMove(MoveType _moveType, std::array<int,2> _offset, bool _ignorePieces){
    moveType = _moveType;
    offset = _offset;
    ignorePieces = _ignorePieces;
}

PieceMove::~PieceMove(){}

MoveType PieceMove::getMoveType(){
    return moveType;
}

std::array<int,2> PieceMove::getOffset(){
    return offset;
}

bool PieceMove::isIgnorePieces(){
    return ignorePieces;
}

bool PieceMove::operator==(const PieceMove& move){
    if((moveType == move.moveType) && (offset == move.offset)
    && (ignorePieces == move.ignorePieces)){
        return true;
    }else{
        return false;
    }
}