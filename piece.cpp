#include "piece.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Piece::Piece(){}
Piece::~Piece(){}

string Piece::getType(){
    return type;
}

void Piece::getPos(vector<int>& vector){
    for (int i =0; i < pos.size(); i++){
        vector[i] = pos[i];
    }
}

string Piece::getTexture(){
    return texture;
}

void Piece::getMoves(vector<vector<int>>& vector){
    for (int i = 0; i < moves.size(); i++){
        for (int j = 0; j < moves[i].size(); j++){
            vector[i][j] = moves [i][j];
        }
    }
}

bool Piece::getColor(){
    return color;
}

Pawn::Pawn(vector<int> _pos, bool _color){
    type = "Pawn";
    pos = _pos;
    if (color){
        texture = "sprites/blackpawn.png";
    }else{
        texture = "sprites/pawn.png";
    }
    moves = {{0,1}, {0,2}};
    color = _color;
};

