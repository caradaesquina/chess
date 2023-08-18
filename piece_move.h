#ifndef PIECE_MOVE
#define PIECE_MOVE

#include <array>

enum MoveType{
    //ALL PIECES, EXCEPT PAWNS
    movementOrCapture,

    // KING MOVEMENTS
    littleCastle, 
    bigCastle, 

    // PAWN MOVEMENTS
    firstMovement,
    movement,
    capture, 
    promotion,
    enPassant 
};

class PieceMove{
    private:
        MoveType moveType;
        std::array<int,2> offset;
        bool ignorePieces; // true for knight, false for the rest of the pieces
    public:
        PieceMove(MoveType, std::array<int,2>, bool _isIgnorePieces = false);
        ~PieceMove();
        MoveType getMoveType();
        std::array<int,2> getOffset();
        bool isIgnorePieces();
};


#endif