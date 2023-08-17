#ifndef BOARD
#define BOARD

#include "square.h"
#include "piece.h"
#include <array>
#include <vector>

class Board{
    private:
        std::array<Square*, 64> squares;
        std::vector<Piece*> pieces;
    public:
        Board();
        ~Board();
        int getPiecesNumber(int);
        Piece* getPiece(int);
};

#endif