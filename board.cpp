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
    Pawn* tstPawn = new Pawn(true, getSquare({2,1}), 99);
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
Piece* Board::getPiece(int code){
  try{
    for(auto& piece : pieces){
      if(piece->getCode() == code){ 
        return piece;
      }
    } 
    throw std::runtime_error("Piece code not present.");
  }catch (std::exception e){
    std::cerr << e.what() << std::endl;
  }
}

void Board::removePiece(Piece* pieceToDelete){
  int i = 0;
  for(auto& piece : pieces){
    if(piece->getCode() == pieceToDelete->getCode()){
      pieces.erase(pieces.begin() + i);
    }
    i++;
  } 
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
