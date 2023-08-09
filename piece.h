#ifndef PIECE
#define PIECE

#include <vector>
#include <string>

using namespace std;

class Piece{
    protected:
        string type;
        vector<int> pos;
        string texture;
        vector<vector<int>> moves;
        bool color;
        
    public:
        Piece();
        ~Piece();
        virtual string getType();
        virtual void getPos(vector<int>&);
        virtual string getTexture();
        virtual void getMoves(vector<vector<int>>&);
        virtual bool getColor();

};

class Pawn : public Piece{
    public:
        Pawn(vector<int>,bool);

};

#endif