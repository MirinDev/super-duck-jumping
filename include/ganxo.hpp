#ifndef GANXO_HPP
#define GANXO_HPP
#include <stdio.h>
#include <math.h>
#include "SDL2/SDL.h"
#include "obstacle.hpp"
bool colision(SDL_Rect *r, SDL_Rect *rr);
float lerp(float a, float b, float f);

class Ganxo{
    private:
        float r=0.0;
        SDL_Point s={0, 0};
    public:
        Ganxo(int x, int y);
        void draw(SDL_Renderer *renderer);
        void set(int sx, int sy);
        void update(Obstacle *obs[], int size);
        void attack(SDL_Rect *re);

        SDL_Point rect={0, 0};
        SDL_Point point={0, 0};
        bool push=false;
        bool on=false;
};


#endif