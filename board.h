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
        void removePiece(Piece* pieceToDelete);
        std::vector<Piece*> getPieces();
        Square* getSquare(std::array<int,2> squarePos);
        std::array<Square*, 64> getSquares();
        void drawASCIIBoard();
        Board& operator=(const Board&board);
};

#endif
