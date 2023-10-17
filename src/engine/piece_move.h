//Class describing piece movementation and capturing
//Note that GameEngine class handles its functionalities, PieceMove only describes them.
//Lucas Moura,2023
#ifndef PIECEMOVE_H
#define PIECE_MOVE_H

#include <array>

enum MoveType{
    //all pieces moves
    MOVEMENT,
    CAPTURE,

    //pawn-only moves
    ENPASSANT,
    PROMOTION,

    //king moves
    BIGCASTLE,
    SMALLCASTLE,

};

class PieceMove{
    private:
        MoveType moveType;
        std::array<int,2> offset;
    public:
        PieceMove(MoveType mv, std::array<int,2> off) {moveType = mv; offset = off;}
        ~PieceMove() {}
};

#endif