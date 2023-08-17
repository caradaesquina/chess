#ifndef PIECE
#define PIECE

#include "square.h"
#include <array>

class Piece{
    protected:
        /* 0 - pawn, 1 - knight, 2 - rook, 3 - bishop,
        4- rook, 5 - queen, 6 - king                */
        int type;
        bool color;
        Square square;
    public:
        Piece();
        ~Piece();
        int getType();
        bool getColor();
        Square getSquare();
        void setSquare(Square);
        std::array<int,2> getPos();
        virtual void getMoves() = 0;
};

class Pawn : public Piece{
    public:
        Pawn(bool, Square);
        void getMoves();
};


#endif
