#ifndef PIECE
#define PIECE

#include <vector>
#include <string>
using namespace std;

class Piece{
    protected:
        int type;
        vector<int> pos;
        vector<vector<int>> moves;
        bool color;
        
    public:
        Piece();
        ~Piece();
        virtual int getType();
        virtual void getPos(vector<int>&);
        virtual void getMoves(vector<vector<int>>&);
        virtual int getMoveNumber();
        virtual bool getColor();
        virtual void setPos(vector<int>&);

};

class Pawn : public Piece{
    public:
        Pawn(vector<int>,bool);

};

class Knight : public Piece{
    public:
        Knight(vector<int>, bool);
};

class Rook : public Piece{
    public:
        Rook(vector<int>, bool);
};

class Bishop : public Piece{
    public:
        Bishop(vector<int>, bool);
};

class Queen : public Piece{
    public:
        Queen(vector<int>, bool);
};

class King : public Piece{
    public:
        King(vector<int>, bool);
};

#endif