#ifndef SQUARE
#define SQUARE

#include <array>

class Square{
    private:
        std::array<int,2> pos;
        bool color;
    public:
        Square();
        Square(std::array<int,2>, bool);
        ~Square();
        std::array<int,2> getPos();
        bool getColor();
};
#endif