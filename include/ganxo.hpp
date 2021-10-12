#ifndef GANXO_HPP
#define GANXO_HPP
#include <stdio.h>
#include <math.h>
#include "SDL2/SDL.h"
#include "obstacle.hpp"
bool colision(SDL_Rect *r, SDL_Rect *rr);

class Ganxo{
    private:
        int rad=20;
        bool on=false;
        SDL_RendererFlip f=SDL_FLIP_NONE;
    public:
        Ganxo(int x, int y);
        void draw(SDL_Renderer *renderer);
        void set(int sx, int sy);
        void update(Obstacle *obs[], int size);
        void attack(SDL_RendererFlip flip);
        double r;

        SDL_Point rect={0, 0};
        SDL_Point point={0, 0};
        bool push=false;
};


#endif