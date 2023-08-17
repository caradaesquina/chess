#include "board.h"
#include <stdexcept>
#include <iostream>

Board::Board(){
    //initializing the 64 squares
    bool color = true;
    for (int i =0; i < 8; i++){
        for(int j=0; j< 8; j++){
            Square* square = new Square(std::array<int,2>{i,j}, color);
            squares[i*8 + j] = square;
            color = !color;        
        }
    }

    for(int i = 0; i < 8; i++){
        Pawn* pawn = new Pawn(false,squares[8+i]);
        pieces.push_back(pawn);
    }
    for(int i = 0; i < 8; i++){
        Pawn* pawn = new Pawn(true,squares[42+i]);
        pieces.push_back(pawn);
    }

}

Board::~Board(){
    for (auto& i : squares){
        delete(i);
    }
    for (auto& i : pieces){
        delete(i);
    }
}

Piece* Board::getPiece(int pos){
    try{
        if(pos > pieces.size()-1){
            throw std::out_of_range("Piece out of index");
        }
    }catch(const std::out_of_range& e){
        std::cerr << e.what() << std::endl;
    }
    return pieces[pos];
}