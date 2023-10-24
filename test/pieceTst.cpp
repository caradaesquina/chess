//testing the piece class
//Lucas Moura, 2023

#include "../src/engine/piece.h"
#include <iostream>

int main(){
    Square* sq = new Square(0, (std::array<int,2>) {0,0});
    Pawn* p = new Pawn(true, sq);
    std::cout << p->getColor() << std::endl;
    return 0;
}