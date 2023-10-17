//A square on the board. Board class handles them as a whole.
//Lucas Moura 2023

#ifndef SQUARE_H
#define SQUARE_H

#include <array>

class Square{
    private:
        bool color; // 0 - white, 1 - black
        std::array<int,2> globalPos;
    public:
        Square(int col, std::array<int,2> pos) {color = col, globalPos = pos;}
        ~Square() {}
        int getColor() {return color;}
        std::array<int,2> getGlobalPos() {return globalPos;}
        bool operator==(const Square* sq) {
            if (pos == sq->pos) 
                return true; 
            else 
                return false;}
};

#endif