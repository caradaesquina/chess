#ifndef PIECE
#define PIECE

#include "square.h"
#include "piece_move.h"

#include <array>
#include <vector>

class Piece{
    protected:
        /* 0 - pawn, 1 - knight, 2 - rook, 3 - bishop,
        4- rook, 5 - queen, 6 - king                */
        int type;
        // false - white, true - black
        bool color;
        Square* square;
        std::vector<PieceMove*> allPieceMoves;
    public:
        Piece();
        ~Piece();
        int getType();
        bool getColor();
        Square* getSquare();
        void setSquare(Square*);
        std::array<int,2> getPos();
        virtual std::vector<PieceMove*>  getMoves()=0;
};

class Pawn : public Piece{
    public:
        Pawn(bool, Square*);
        std::vector<PieceMove*> getMoves();
};

#endif
