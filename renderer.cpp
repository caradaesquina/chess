#include "renderer.h"
#include "square.h"
#include <stdexcept>
#include <SLFML/Graphics.hpp>

Renderer::Renderer(){
    if (running == true){
        throw runtime_error;
    }
    running = true;
}

Renderer::~Renderer(){
    running = false;
}

void Renderer::renderWindow(int width, int height, string name){
    sf::Window window(sf::VideoMode(width, height), name)
}