#include "board.h"
#include <iostream>

int main(){
    Board board;
    std::cout << "Piece type: " << board.getPiece(15)->getType() << std::endl;
    std::cout << "Piece at: " << board.getPiece(15)->getPos()[0] << ", " << board.getPiece(15)->getPos()[1] << std::endl;
    std::vector<PieceMove*> p = board.getPiece(0)->getMoves();
    std::cout << p[0]->getMoveType(); << std::endl;
    std::cout << "Goddamn!" << std::endl;
    return 0;
}