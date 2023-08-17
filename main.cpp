#include "piece.h"
#include "square.h"
#include "board.h"
#include <array>
#include <iostream>

int main(){
    Square square(std::array<int,2> {0,1}, true);
    Pawn pawn(false, square);
    std::cout << "Piece type: " << pawn.getType() << std::endl;
    std::cout << "Position: " << pawn.getSquare().getPos()[0] << ", " << pawn.getPos()[1] << std::endl;
    return 0;
}