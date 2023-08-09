#ifndef RENDERER
#define RENDERER

#include "square.h"
#include <string>


class Renderer{
    private:
        static bool running;
    public:
        Renderer();
        ~Renderer();
        void renderWindow(int, int, string);
        void drawSquare(Square);
};

#endif