#ifndef GAME_HANDLER
#define GAME_HANDLER

#include "board.h"
#include <vector>
#include <array>

class GameHandler{
    private:
        Board* board;
        std::vector<PieceMove*> getPawnMoves(Piece* piece);

        /* Checks if piece lands on the same square of another*/
        bool checkPieceSuperposition(Piece* piece, PieceMove* move, bool checkColor); 

        /* Checks if piece would jump over another on its movement*/
        bool checkPieceInterception(Piece* piece, PieceMove* move);
        
        //Captures a piece on the board, with the argument being the piece that is going to do the capture 
        void capturePiece(Piece* piece);

    public:
        GameHandler(Board* _board);
        ~GameHandler();
        std::vector<PieceMove*> getAvaiableMoves(Piece* piece);
        bool movePiece(Piece* piece, PieceMove* move);
};

#endif
