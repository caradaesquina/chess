//Exceptions thrown by the Board class.
//Lucas Moura 2023

#include <stdexcept>
#include <iostream>
#include <string>

class BoardException : public std::exception {
    private:
        std::string message;
    public:
        OutOfRangeSquare(std::string msg) : message(msg) {}
        std::string what() {return message};
};
class OutOfRangeSquare : public BoardException{};