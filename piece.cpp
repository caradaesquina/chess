#include "piece.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Piece::Piece(){}
Piece::~Piece(){}

int Piece::getType(){
    return type;
}

void Piece::getPos(vector<int>& vector){
    for (int i =0; i < pos.size(); i++){
        vector[i] = pos[i];
    }
}

vector<vector<int>> Piece::getMoves(){
    return moves;
}

int Piece::getMoveNumber(){
    return moves.size();
}

bool Piece::getColor(){
    return color;
}

void Piece::setPos(vector<int>& _pos){
    for (int i =0; i<pos.size(); i++){
        pos[i] = _pos[i];
    }
}

Pawn::Pawn(vector<int> _pos, bool _color){
    type = 0;
    pos = _pos;
    moves = {{0,1}, {0,2}};
    color = _color;
};

Knight::Knight(vector<int> _pos, bool _color){
    type = 1;
    pos = _pos;
    moves = {{}};
    color = _color;
}

Rook::Rook(vector<int> _pos, bool _color){
    type = 2;
    pos = _pos;
    moves = {{}};
    color = _color;
}

Bishop::Bishop(vector<int> _pos, bool _color){
    type = 3;
    pos = _pos;
    moves = {{}};
    color = _color;
}

Queen::Queen(vector<int> _pos, bool _color){
    type = 4;
    pos = _pos;
    moves = {{}};
    color = _color;
}

King::King(vector<int> _pos, bool _color){
    type = 5;
    pos = _pos;
    moves = {{}};
    color = _color;
}