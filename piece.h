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
        int timesMoved;
        
    public:
        Piece();
        ~Piece();
        virtual int getType();
        virtual vector<int> getPos();
        virtual vector<vector<int>> getMoves();
        virtual bool getColor();
        virtual void setPos(vector<int>&);
        virtual void setPos(int,int);


};

class Pawn : public Piece{
    private:
        vector<int> initialPos;
    public:
        Pawn(vector<int>,bool);
        vector<vector<int>> getMoves();
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