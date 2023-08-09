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
    for (int i = 0; i < piecesVector.size();i++){
        sf::Sprite sprite;
        if (piecesVector[i].getColor()){
            sprite.setTexture(texturesVector[1]);
        }else{
            sprite.setTexture(texturesVector[0]);
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

void initializeTextures(vector<sf::Texture>& textureVector){ // 0,1: p;
    static sf::Texture whitePawnTexture;
    if(!whitePawnTexture.loadFromFile("sprites/pawn.png")){
        throw runtime_error("failed to load texture");
    }
    whitePawnTexture.loadFromFile("sprietes/pawn.png");
    static sf::Texture blackPawnTexture;
    if(!blackPawnTexture.loadFromFile("sprites/blackpawn.png")){
        throw runtime_error("failed to load texture");
    }
    blackPawnTexture.loadFromFile("sprietes/blackpawn.png");
    textureVector.push_back(whitePawnTexture);
    textureVector.push_back(blackPawnTexture);
}