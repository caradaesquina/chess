#include "game_handler.h"
#include <iostream>
#include <string>
#include <exception>

void debbugingLog();
std::string menu();
void staticMenu();

Board* board = new Board;
GameHandler gameHandler(board); 

int main(){
  while(true){
    staticMenu();
    std::string a = menu();
    system("clear");
    if(a == "1"){break;}
    else{
      std::cout << a << std::endl;
    }
  }
  return 0;
}

void debbugingLog(){
}

std::string menu(){
  std::string op;
  std::cin >> op;
  if(op == "q"){
    return "1";
  }
  if(op == "cow"){
    return "mooo";
  }
  if(op.length() == 2){
      if((op[0] < 65) || ((op[0] > 72) && (op[0] < 97)) || (op[0] > 104) || (op[1] < 49) || (op[1] > 56)){  // check for values between A-H and a-h ASCII
        return "Invalid position.";
      }
  }else{
    return "Invalid command.";
  }
  return "aok";
}

void staticMenu(){
  board->drawASCIIBoard();
  std::cout << "Select a piece or hit (q) to quit: ";
}
