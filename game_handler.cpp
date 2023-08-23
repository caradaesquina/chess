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
                if((checkPieceSuperposition(piece,move,false)) || (checkPieceInterception(piece,move))){
                    break;
                }
                avaiablePawnMoves.push_back(move);
            }
        }break;
        case movement:{
            /* Pawn's movements are special because they
            are disjointed from their captures, a pawn cannot move
            to a space where other piece resides*/
            if((checkPieceSuperposition(piece,move,false)) || (checkPieceInterception(piece,move))){
                    break;
                }
            avaiablePawnMoves.push_back(move);
        }
        case capture:{
            if(checkPieceSuperposition(piece,move,true)){
                avaiablePawnMoves.push_back(move);
            }else{
                break;
            }
        }break;
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
            if(move->getMoveType() == capture){
              capturePiece(piece);
            }
            return true;
        }
    }
    return false;
}

bool GameHandler::checkPieceSuperposition(Piece* piece, PieceMove* move, bool checkColor){
    int x_pos = piece->getSquare()->getPos()[0] + move->getOffset()[0];
    int y_pos = piece->getSquare()->getPos()[1] + move->getOffset()[1];
    Square* sq = board->getSquare({x_pos, y_pos});
    for (auto& otherPiece : board->getPieces()){
        if(otherPiece->getCode() != piece->getCode()){
            if(otherPiece->getSquare() == sq){
              if (checkColor){
                  if(otherPiece->getColor() != piece->getColor()){
                      return true;
                  }
              }else{
                return true;
              }
            }
        }
    }
    return false;
}

bool GameHandler::checkPieceInterception(Piece* piece, PieceMove* move){
    int x_pos = piece->getSquare()->getPos()[0] + move->getOffset()[0];
    int y_pos = piece->getSquare()->getPos()[1] + move->getOffset()[1];
    if (board->getSquare({x_pos, y_pos}) == nullptr){
        std::cout << "a";
        return false;
    }
    Square* sq = board->getSquare({x_pos, y_pos});
    for (auto& otherPiece : board->getPieces()){
        if(otherPiece->getCode() != piece->getCode()){
            if(otherPiece->getPos()[0] == piece->getPos()[0]){
                if(sq->getPos()[1] >= otherPiece->getPos()[1]){
                    return true;
                }
            }
            if(otherPiece->getPos()[1] == piece->getPos()[1]){
                if(sq->getPos()[0] >= otherPiece->getPos()[0]){
                    return true;
                }
            }
        }
    }
    return false;
}

void GameHandler::capturePiece(Piece* piece){
  for(auto& otherPiece : board->getPieces()){
    if(otherPiece->getCode() != piece->getCode()){
      if(otherPiece->getPos() == piece->getPos()){
        board->removePiece(otherPiece);
        return;
      }
    }
  }
}
