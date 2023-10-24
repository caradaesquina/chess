#include "board.h"
#include "exceptions/board_excep.h"

//Board* boardInstance = nullptr;

Board::Board(){
    generateSquares();
    generatePieces();
}

void Board::generateSquares(){
    bool color = true;
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            Square* sq = new Square(color, std::array<int,2> {i,j});
            boardSquares.push_back(sq);
            color = !color;
        }
        color = !color;
    }
}

void Board::generatePieces(){ // TODO

}

Board::~Board(){
    for (auto& sq: boardSquares){
        delete sq;
    }
    for (auto& p: boardPieces){
        delete p;
    }
}

Board* Board::getInstance(){
    if(boardInstance == nullptr){
        boardInstance = new Board();
    }
    return boardInstance;
}

std::vector<Square*> Board::getSquares(){
    return boardSquares;
}

std::vector<Piece*> Board::getPieces(){
    return boardPieces;
}

Piece* Board::getPiece(int code){
    for (auto& p : boardPieces){
        if (code == p->getCode()){
            return p;
        }
    }
    return nullptr;
}

Piece* Board::getPiece(Square* piece_sq){
    std::array sqPos = piece_sq->getGlobalPos();
    try{
        if((sqPos[0] < 1) || (sqPos[0] > 8) || (sqPos[1] < 1) || (sqPos[1] > 8)){
            throw OutOfRangeSquare("Couldnt get piece - index out of range!");
        }
        for (auto& p: boardPieces){
            if (piece_sq = p->getActualSquare()){
                return p;
            }
        }
        return nullptr;
    }catch (BoardException& board_excep){
        std::cerr << "Caught BoardException:" << board_excep.what() << std::endl;
    }
}

Square* Board::getSquare(std::array<int,2> sqPos){
    try{
        if((sqPos[0] < 1) || (sqPos[0] > 8) || ( sqPos[1] < 1) || (sqPos[1] > 8)){
            throw OutOfRangeSquare("Couldnt get square - index out of range!");
        }
        for(auto& sq : boardSquares){
            if(sqPos == sq->getGlobalPos()){
                return sq;
            }
        }
    }catch(BoardException& board_excep){
        std::cerr << "Caught BoardException: " << board_excep.what() << std::endl;
    }
}