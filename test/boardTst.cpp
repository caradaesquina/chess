//Test program for the board class.
//Lucas Moura, 2023

#include "../src/engine/board.h"
#include <iostream>

int main(){
    Board* b = Board::getInstance();
    std::vector<Square*> squares = b->getSquares();
    int i = 0;
    for (auto& sq : squares){
        std::cout << sq->getColor() << "  ";
        i++;
        if (i == 8) {i = 0; std::cout << std::endl << std::endl;}
    }

    return 0;
}