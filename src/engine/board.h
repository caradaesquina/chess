//Class defining the behavoir of the chess board as a whole.
//All squares and piece (in-play) exist at the board, and only one can be instatiated at a time (singleton).
//Lucas Moura, 2023


//The board coordinates are such:
//a  b  c  d  e  f  g  h
//                       8
//                       7
//                       6
//                       5
//                       4
//                       3
//                       2
//                       1

//For consistency, coords are expressed in chess notation, with a = 1; h = 8


#include "piece.h"
#include <vector>
#include <array>

class Board{
    private:
        std::vector<Square*> boardSquares;
        std::vector<Piece*> boardPieces;
        void generateSquares(); 
        void generatePieces(); // starts all pieces in standard position
        Board();
        static Board* boardInstance;
    public:
        static Board* getInstance();
        ~Board();
        std::vector<Square*> getSquares();
        std::vector<Piece*> getPieces();
        Piece* getPiece(int); //get a specific piece
        Piece* getPiece(Square*); //get the piece at a specific square (no piece = NULL)
        Square* getSquare(std::array<int, 2>) //returns the square at a specific position (global position)


        //as Board is a singleton, it shouldnt be possible to be copied
        Board(Board& b) = delete;
        void operator=(const Board& b) = delete;
};