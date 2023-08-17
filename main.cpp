#include "piece.h"
#include "square.h"
#include "board.h"
#include <array>
#include <iostream>

int main(){
    Board board;
    std::cout << "Piece type: " << board.getPiece(15)->getType() << std::endl;
    std::cout << "Piece at: " << board.getPiece(15)->getPos()[0] << ", " << board.getPiece(15)->getPos()[1] << std::endl;
    return 0;
}