#include "game_handler.h"
#include <iostream>

int main(){
    Board* board = new Board;
    GameHandler gameHandler(board);
    int i = 0;
    Piece* piece = board->getPiece(0);
    Piece* piece1 = board->getPiece(1);
    std::cout << "Piece type: " << piece->getType() << std::endl;
    std::cout << "Piece at: " << piece->getPos()[0] << ", " << piece->getPos()[1] << std::endl;
    std::cout << "Piece1 at: " << piece1->getPos()[0] << ", " << piece1->getPos()[1] << std::endl;
    std::cout << "Avaiable Moves: ";
    for (auto& move : gameHandler.getAvaiableMoves(piece)){
        std::cout  << "("<<move->getOffset()[0] << ", " << 
        move->getOffset()[1] << ") ";
    }
    std::cout << std::endl;

    gameHandler.movePiece(piece, piece->getMoves()[0]);
    std::cout << "Moved Piece! Piece at: " << piece->getPos()[0] << ", " << piece->getPos()[1] << std::endl;
    std::cout << "Goddamn!" << std::endl;


    return 0;
}