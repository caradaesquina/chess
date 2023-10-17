//Classes definig all chess pieces, its atributes and positions.
//Note that piece movementation and capture is handled by GameEngine, not this class
//Lucas Moura, 2023

#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "square.h"
#include "piece_move.h"

enum PieceType{
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

class Piece{
    protected:
        bool color; //0 - white, 1 - black
        int code; // a unique piece identifier
        PieceType type;
        Square* actualSquare;
        Square* originalSquare; //used for first pawn movement, casteling, promotion
        bool moved; // used for casteling
        std::vector<PieceMove*> moves;
        void setSquare(Square*);
        virtual void generateMoves() = 0;
    public:
        Piece(bool, Square*);
        virtual ~Piece();
        bool getColor();
        int getCode();
        int getPieceType();
        Square* getActualSquare();
        Square* getOriginalSquare();
        bool hasMoved();
        std::vector<PieceMove*> getMoves();
};

class Pawn: public Piece{
    private:
        void generateMoves();
    public:
        Pawn(bool, Square*);
        ~Pawn();
};

#endif