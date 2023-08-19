#include "board.h"
#include <stdexcept>
#include <array>
#include <iostream>

Board::Board(){
    bool color = true;
    for (int i =0; i < 8; i++){
        for(int j=0; j< 8; j++){
            Square* square = new Square({i,j}, color);
            squares[i*8 + j] = square;
            color = !color;        
        }
    }

    for(int i = 0; i < 8; i++){
        Pawn* pawn = new Pawn(false,getSquare({1,i}),i);
        std::cout << "Constructing Pawn: " << pawn->getColor() <<  ", " << "code: " << pawn->getCode() << std::endl;
        pieces.push_back(pawn);
    }
    for(int i = 0; i < 8; i++){
        Pawn* pawn = new Pawn(true,getSquare({6,i}),i+8);
        std::cout << "Constructing Pawn: " << pawn->getColor() <<  ", " << "code: " << pawn->getCode() << std::endl;
        pieces.push_back(pawn);
    }
    Pawn* tstPawn = new Pawn(false, getSquare({4,0}), 99);
    pieces.push_back(tstPawn);
}


Board::~Board(){
    for (auto& i : squares){
        delete(i);
    }
    for (auto& i : pieces){
        delete(i);
    }
}

//TODO: refactor method to use piece code
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

std::vector<Piece*> Board::getPieces(){
    return pieces;
}

Square* Board::getSquare(std::array<int,2> squarePos){
    for(auto square : squares){
        if(square->getPos() == squarePos){
            return square;
        }
    }
    return nullptr;
}

std::array<Square*, 64> Board::getSquares(){
    return squares;
}

Board& Board::operator=(const Board& board){
    squares = board.squares;
    pieces = board.pieces;
    return *this;
}