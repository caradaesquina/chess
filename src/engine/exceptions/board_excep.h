//Exceptions thrown by the Board class.
//Lucas Moura 2023

#include <stdexcept>
#include <iostream>
#include <string>

class BoardException : public std::exception {
    protected:
        std::string message;
    public:
        BoardException(const std::string msg) {message = msg;}
        std::string what() {return message;}
};
class OutOfRangeSquare : public BoardException{
    public:
        OutOfRangeSquare(const std::string msg) : BoardException(msg) {}
        
};