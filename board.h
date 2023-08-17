#ifndef BOARD
#define BOARD

#include "square.h"
#include "piece.h"
#include <array>
#include <vector>

class Board{
    private:
        std::array<SQUARE::Square, 64> squares;
        std::vector<PIECE::Piece> pieces;
    public:
        Board();
        ~Board();
};

#endif