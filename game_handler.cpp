#include "game_handler.h"

#include <vector>
#include <iostream>

GameHandler::GameHandler(Board* _board){
    std::cout << "Initializing GameHandler..." << std::endl;
    board = _board;
    std::cout << "Initialized GameHandler." << std::endl;
}
GameHandler::~GameHandler(){
    delete(board);
}

std::vector<PieceMove*> GameHandler::getPawnMoves(Piece* piece){
    std::vector<PieceMove*> avaiablePawnMoves;
    for (auto& move : piece->getMoves()){
        switch (move->getMoveType())
        {
        case firstMovement:{
            /* The first double movement of the pawn can only
            be excuted if it is the first move of the pawn,
            that is, the pawn hasn't moved yet and it is located ate its
            original position*/
            if(piece->getSquare() != piece->getOriginalSquare()){
                break;
            }else{
                avaiablePawnMoves.push_back(move);
            }
        }break;
        case movement:{
            /* Pawn's movements are special because they
            are disjointed from their captures, a pawn cannot move
            to a space where other piece resides*/
            if(checkPieceSuperposition(piece,move)){
                break;
            };
            avaiablePawnMoves.push_back(move);
        }
        default:
            break;
        }
    }
    return avaiablePawnMoves;
}

std::vector<PieceMove*> GameHandler::getAvaiableMoves(Piece* piece){
    std::vector<PieceMove*> avaiableMoves;
    switch (piece->getType()){
    case 0:{ //pawn
        avaiableMoves = getPawnMoves(piece);
    }break;
    
    default:
        return {};
        break;
    }
    return avaiableMoves;
}

bool GameHandler::movePiece(Piece* piece, PieceMove* move){
    for (auto& avaiableMove : getAvaiableMoves(piece)){
        if (avaiableMove == move){
            int x_pos = piece->getSquare()->getPos()[0] + move->getOffset()[0];
            int y_pos = piece->getSquare()->getPos()[1] + move->getOffset()[1];
            piece->setSquare(board->getSquare({x_pos, y_pos}));
            piece->setHasMoved(true);
            return true;
        }
    }
    return false;
}

bool GameHandler::checkPieceSuperposition(Piece* piece, PieceMove* move){
    bool status = false;
    int x_pos = piece->getSquare()->getPos()[0] + move->getOffset()[0];
    int y_pos = piece->getSquare()->getPos()[1] + move->getOffset()[1];
    Square* sq = board->getSquare({x_pos, y_pos});
    for(auto& otherPiece : board->getPieces()){
        if(otherPiece->getCode() != piece->getCode()){
            if (sq == otherPiece->getSquare()){
                status = true;
                break;
            }
        }
    }
    return status;
}