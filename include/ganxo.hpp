#ifndef GANXO_HPP
#define GANXO_HPP
#include <stdio.h>
#include <math.h>
#include "SDL2/SDL.h"

class Ganxo{
    private:
        SDL_Point rect={0, 0};
        int x=0;
        int y=0;
        bool pleft=false;
        bool pright=false;
        int mode=1;
    public:
        Ganxo(int x, int y);
        void draw(SDL_Renderer *renderer);
        void set(int x, int y, SDL_RenderFlip *flip);
        void update();
        double r;
};


#endif