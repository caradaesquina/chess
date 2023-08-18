#ifndef PIECE_MOVE
#define PIECE_MOVE

#include <array>

enum MoveType{
    /* Despite moving the piece to the same position, a move
    can either be a simple movement or capture an enemy piece
    except pawns, where the movement and captures are disjointed*/
    movement,
    capture, 

    // KING MOVEMENTS
    littleCastle, 
    bigCastle, 

    // PAWN MOVEMENTS
    firstMovement,
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
        bool operator == (const PieceMove& move);
};


#endif