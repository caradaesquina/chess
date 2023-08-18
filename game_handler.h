#ifndef GAME_HANDLER
#define GAME_HANDLER

#include "board.h"
#include <vector>
#include <array>

class GameHandler{
    private:
        Board* board;
        std::vector<PieceMove*> getPawnMoves(Piece* piece);
        bool checkPieceSuperposition(Piece* piece, PieceMove* move);
    public:
        GameHandler(Board* _board);
        ~GameHandler();
        std::vector<PieceMove*> getAvaiableMoves(Piece* piece);
        bool movePiece(Piece* piece, PieceMove* move);
};

#endif