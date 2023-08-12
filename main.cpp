#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "renderer.h"
#include "square.h"
#include "piece.h"


#define BROWN sf::Color(196,164,132)
#define WHITE sf::Color(200,200,200)
#define GREEN sf::Color(34,139,34)

void initializeSquares(vector<Square>&, vector<sf::RectangleShape>&);
void drawSquares(sf::RenderWindow& , vector<sf::RectangleShape>&);

void initializeTextures(vector<sf::Texture>&);

void initializePieces(vector<Piece>&, vector<sf::Sprite>&);
void initializeSprites(vector<Piece>&, vector<sf::Sprite>&, vector<sf::Texture>&);
void drawPieces(sf::RenderWindow&, vector<sf::Sprite>&);

void clearMoves(vector<sf::CircleShape>&);
void drawMoves(sf::RenderWindow&, vector<sf::CircleShape>&);

void handleMousePress(sf::RenderWindow&, vector<Piece>&,vector<sf::Sprite>&, vector<sf::CircleShape>&);

void drawPieceMoves(Piece, sf::Sprite, vector<sf::CircleShape>&);
void movePiece(Piece*, sf::Sprite&, sf::CircleShape&, vector<sf::CircleShape>&);

using namespace std;

int main()
{
    vector<Square> squaresVector;
    vector<sf::RectangleShape> drawSquaresVector;
    vector<Piece> piecesVector;
    vector<sf::Sprite> drawPiecesVector;
    vector<sf::Texture> texturesVector;
    vector<sf::CircleShape> movesVector;
    initializeSquares(squaresVector, drawSquaresVector);
    initializeTextures(texturesVector);
    initializePieces(piecesVector, drawPiecesVector);
    initializeSprites(piecesVector, drawPiecesVector, texturesVector);


    sf::RenderWindow window(sf::VideoMode(512, 512), "Teste");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if(event.mouseButton.button == sf::Mouse::Left){
                            handleMousePress(window, piecesVector, drawPiecesVector, movesVector);

                    }
                    break;
            }
        }
        window.clear();
        drawSquares(window, drawSquaresVector);
        drawPieces(window, drawPiecesVector);
        drawMoves(window, movesVector);
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

void initializePieces(vector<Piece>& piecesVector, vector<sf::Sprite>& drawPiecesVector){
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
    Queen wQueen({3,7},false);
    Queen bQueen({3,0},true);
    King wKing({4,7},false);
    King bKing({4,0},true);
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
    piecesVector.push_back(wQueen);
    piecesVector.push_back(bQueen);
    piecesVector.push_back(wKing);
    piecesVector.push_back(bKing);

}

void initializeSprites(vector<Piece>& piecesVector, vector<sf::Sprite>& drawPiecesVector, vector<sf::Texture>& texturesVector){
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
            case 4:
                if (piecesVector[i].getColor()){
                    sprite.setTexture(texturesVector[9]);
                }else{
                    sprite.setTexture(texturesVector[8]);
                }
                break;
            case 5:
                if (piecesVector[i].getColor()){
                    sprite.setTexture(texturesVector[11]);
                }else{
                    sprite.setTexture(texturesVector[10]);
                }
                break;
        }
        
        vector<int> pos = piecesVector[i].getPos();
        sprite.setPosition(pos[0]*64,pos[1]*64);
        drawPiecesVector.push_back(sprite);
        } 
    }   

void drawPieces(sf::RenderWindow& win, vector<sf::Sprite>& drawPiecesVector){
    for (int i =0; i <drawPiecesVector.size(); i++){
        win.draw(drawPiecesVector[i]);
    }
}

void initializeTextures(vector<sf::Texture>& textureVector){ 
    
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
    static sf::Texture queenTexture;
    if(!queenTexture.loadFromFile("sprites/queen.png")){
        throw runtime_error("failed to load texture");
    }
    queenTexture.loadFromFile("sprites/queen.png");
    static sf::Texture blackQueenTexture;
    if(!blackQueenTexture.loadFromFile("sprites/blackqueen.png")){
        throw runtime_error("failed to load texture");
    }
    blackQueenTexture.loadFromFile("sprites/blackqueen.png");
    static sf::Texture kingTexture;
    if(!kingTexture.loadFromFile("sprites/king.png")){
        throw runtime_error("failed to load texture");
    }
    kingTexture.loadFromFile("sprites/king.png");
    static sf::Texture blackKingTexture;
    if(!blackKingTexture.loadFromFile("sprites/blackking.png")){
        throw runtime_error("failed to load texture");
    }
    blackKingTexture.loadFromFile("sprites/blackking.png");
    

    textureVector.push_back(whitePawnTexture);
    textureVector.push_back(blackPawnTexture);
    textureVector.push_back(whiteKnightTexture);
    textureVector.push_back(blackKnightTexture);
    textureVector.push_back(rookTexture);
    textureVector.push_back(blackRookTexture);
    textureVector.push_back(bishopTexture);
    textureVector.push_back(blackBishopTexture);
    textureVector.push_back(queenTexture);
    textureVector.push_back(blackQueenTexture);
    textureVector.push_back(kingTexture);
    textureVector.push_back(blackKingTexture);
}

void drawMoves(sf::RenderWindow& win, vector<sf::CircleShape>& movesVector){
    for(int i = 0; i< movesVector.size(); i++){
        win.draw(movesVector[i]);
    }
}

void clearMoves(vector<sf::CircleShape>& movesVector){
    movesVector.clear();
}

void handleMousePress(sf::RenderWindow& window, vector<Piece>& piecesVector,vector<sf::Sprite>& drawPiecesVector,vector<sf::CircleShape>& movesVector){
    auto mouse_pos = sf::Mouse::getPosition(window); 
    auto translated_pos = window.mapPixelToCoords(mouse_pos);
    static int pieceNum;
    for (int i =0; i < drawPiecesVector.size()  ;i++){
        Piece piece = piecesVector[i];
        sf::Sprite sprite = drawPiecesVector[i];
        if(sprite.getGlobalBounds().contains(translated_pos)){
            drawPieceMoves(piece,sprite, movesVector);
            pieceNum = i;
        }
    }
    for (int i = 0; i < movesVector.size(); i++){
        if(movesVector[i].getGlobalBounds().contains(translated_pos)){
            Piece* piecePtr;
            piecePtr = &piecesVector[pieceNum];
            movePiece(piecePtr, drawPiecesVector[pieceNum], movesVector[i], movesVector);
        }
    }
    
}

void drawPieceMoves(Piece piece, sf::Sprite sprite, vector<sf::CircleShape>& movesVector){
    vector<int> piecePos = piece.getPos();
    cout << "Clicked " << piece.getType() << " at: " << piecePos[0] << ", " << piecePos[1] << endl;
    vector<vector<int>> avaiableMoves = piece.getMoves();
    clearMoves(movesVector);
    for (int i = 0; i<piece.getMoves().size(); i++){
        sf::CircleShape circle(10);
        cout << "created circle!" << endl;
        circle.setFillColor(GREEN);
        int circle_x_pos, circle_y_pos;
        if(piece.getColor()){
            circle_x_pos = (piecePos[0] + avaiableMoves[i][0])*64 + 22;
            circle_y_pos = (piecePos[1]  + avaiableMoves[i][1])*64 + 22;
        }else{
            circle_x_pos = (piecePos[0] - avaiableMoves[i][0])*64 + 22;
            circle_y_pos = (piecePos[1]  - avaiableMoves[i][1])*64 + 22;
        }
        circle.setPosition(circle_x_pos, circle_y_pos);
        movesVector.push_back(circle);
    } 
}

void movePiece(Piece* piece, sf::Sprite& sprite, sf::CircleShape& move, vector<sf::CircleShape>& movesVector){
    auto piece_x_pos = move.getPosition().x - 22;
    auto piece_y_pos = move.getPosition().y - 22;
    piece->setPos(move.getPosition().x/64, move.getPosition().y/64);
    sprite.setPosition(piece_x_pos, piece_y_pos);
    clearMoves(movesVector);
}