#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "renderer.h"
#include "square.h"
#include "piece.h"


#define BROWN sf::Color(196,164,132)
#define WHITE sf::Color(200,200,200)

void initializeSquares(vector<Square>&, vector<sf::RectangleShape>&);
void drawSquares(sf::RenderWindow& , vector<sf::RectangleShape>&);

void initializeTextures(vector<sf::Texture>&);

void initializePieces(vector<Piece>&, vector<sf::Sprite>&, vector<sf::Texture>&);
void drawPieces(sf::RenderWindow&, vector<sf::Sprite>&);



using namespace std;

int main()
{
    vector<Square> squaresVector;
    vector<sf::RectangleShape> drawSquaresVector;
    vector<Piece> piecesVector;
    vector<sf::Sprite> drawPiecesVector;
    vector<sf::Texture> texturesVector;
    initializeSquares(squaresVector, drawSquaresVector);
    initializeTextures(texturesVector);
    initializePieces(piecesVector, drawPiecesVector, texturesVector);
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Teste");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        drawSquares(window, drawSquaresVector);
        drawPieces(window, drawPiecesVector);
        window.display();
    }
    return 0;
}

void initializeSquares(vector<Square>& squareVector, vector<sf::RectangleShape>& drawSquareVector){
    bool color = true;
    for (int i = 0; i < 8; i++){
        color = !color;
        for (int j = 0; j < 8; j++){
            Square sq(i,j,color);
            squareVector.push_back(sq);
            color = !color;
        }
    }
    for (int i = 0; i<squareVector.size();i++){
        sf::RectangleShape rect(sf::Vector2f(64,64));
        if(squareVector[i].getColor() == true){
            rect.setFillColor(BROWN);
        }else{
            rect.setFillColor(WHITE);
        }
        rect.setPosition(squareVector[i].getCollumn()*64, squareVector[i].getRow()*64);
        drawSquareVector.push_back(rect);
    } 
}

void drawSquares(sf::RenderWindow& win, vector<sf::RectangleShape>& drawSquareVector){
    for (int i =0; i <drawSquareVector.size(); i++){
        win.draw(drawSquareVector[i]);
    }
}

void initializePieces(vector<Piece>& piecesVector, vector<sf::Sprite>& drawPiecesVector, vector<sf::Texture>& texturesVector){
    for (int i = 0; i < 8; i++){
        Pawn pawn({i,6} ,false);
        piecesVector.push_back(pawn);
    }
    for (int i = 0; i < 8; i++){
        Pawn pawn({i,1} ,true);
        piecesVector.push_back(pawn);
    }
    Knight wKnight1({1,7},false);
    Knight wKnight2({6,7},false);
    Knight bKnight1({1,0},true);
    Knight bKnight2({6,0},true);
    Rook wRook1({0,7},false);
    Rook wRook2({7,7},false);
    Rook bRook1({0,0},true);
    Rook bRook2({7,0},true);
    Bishop wBishop1({2,7},false);
    Bishop wBishop2({5,7},false);
    Bishop bBishop1({2,0},true);
    Bishop bBishop2({5,0},true);
    piecesVector.push_back(wKnight1);
    piecesVector.push_back(wKnight2);
    piecesVector.push_back(bKnight1);
    piecesVector.push_back(bKnight2);
    piecesVector.push_back(wRook1);
    piecesVector.push_back(wRook2);
    piecesVector.push_back(bRook1);
    piecesVector.push_back(bRook2);
    piecesVector.push_back(wBishop1);
    piecesVector.push_back(wBishop2);
    piecesVector.push_back(bBishop1);
    piecesVector.push_back(bBishop2);

    for (int i = 0; i < piecesVector.size();i++){
        static sf::Sprite sprite;
        switch(piecesVector[i].getType()){
            case 0:
                if (piecesVector[i].getColor()){
                    sprite.setTexture(texturesVector[1]);
                }else{
                    sprite.setTexture(texturesVector[0]);
                }
                break;
            case 1:
                if (piecesVector[i].getColor()){
                    sprite.setTexture(texturesVector[3]);
                }else{
                    sprite.setTexture(texturesVector[2]);
                }
                break;
            case 2:
                if (piecesVector[i].getColor()){
                    sprite.setTexture(texturesVector[5]);
                }else{
                    sprite.setTexture(texturesVector[4]);
                }
                break;
            case 3:
                if (piecesVector[i].getColor()){
                    sprite.setTexture(texturesVector[7]);
                }else{
                    sprite.setTexture(texturesVector[6]);
                }
                break;

        }
        
        vector<int> pos(2);
        piecesVector[i].getPos(pos);
        sprite.setPosition(pos[0]*64,pos[1]*64);
        drawPiecesVector.push_back(sprite);
    } 
}


void drawPieces(sf::RenderWindow& win, vector<sf::Sprite>& drawPiecesVector){
    for (int i =0; i <drawPiecesVector.size(); i++){
        win.draw(drawPiecesVector[i]);
    }
}

void initializeTextures(vector<sf::Texture>& textureVector){ // 2,3: p; 0,1 N;
    static sf::Texture whitePawnTexture;
    if(!whitePawnTexture.loadFromFile("sprites/pawn.png")){
        throw runtime_error("failed to load texture");
    }
    whitePawnTexture.loadFromFile("sprites/pawn.png");
    static sf::Texture blackPawnTexture;
    if(!blackPawnTexture.loadFromFile("sprites/blackpawn.png")){
        throw runtime_error("failed to load texture");
    }
    blackPawnTexture.loadFromFile("sprites/blackpawn.png");
    static sf::Texture whiteKnightTexture;
    if(!whiteKnightTexture.loadFromFile("sprites/knight.png")){
        throw runtime_error("failed to load texture");
    }
    whiteKnightTexture.loadFromFile("sprites/knight.png");
    static sf::Texture blackKnightTexture;
    if(!blackKnightTexture.loadFromFile("sprites/blackknight.png")){
        throw runtime_error("failed to load texture");
    }
    blackKnightTexture.loadFromFile("sprites/blackknight.png");
    static sf::Texture rookTexture;
    if(!rookTexture.loadFromFile("sprites/rook.png")){
        throw runtime_error("failed to load texture");
    }
    rookTexture.loadFromFile("sprites/rook.png");
    static sf::Texture blackRookTexture;
    if(!blackRookTexture.loadFromFile("sprites/blackrook.png")){
        throw runtime_error("failed to load texture");
    }
    blackRookTexture.loadFromFile("sprites/blackrook.png");
    static sf::Texture bishopTexture;
    if(!bishopTexture.loadFromFile("sprites/bishop.png")){
        throw runtime_error("failed to load texture");
    }
    bishopTexture.loadFromFile("sprites/bishop.png");
    static sf::Texture blackBishopTexture;
    if(!blackBishopTexture.loadFromFile("sprites/blackbishop.png")){
        throw runtime_error("failed to load texture");
    }
    blackBishopTexture.loadFromFile("sprites/blackbishop.png");

    textureVector.push_back(whitePawnTexture);
    textureVector.push_back(blackPawnTexture);
    textureVector.push_back(whiteKnightTexture);
    textureVector.push_back(blackKnightTexture);
    textureVector.push_back(rookTexture);
    textureVector.push_back(blackRookTexture);
    textureVector.push_back(bishopTexture);
    textureVector.push_back(blackBishopTexture);
}