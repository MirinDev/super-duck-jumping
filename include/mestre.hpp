#ifndef MESTRE_HPP
#define MESTRE_HPP
#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "piriquitin_image.h"
#include "obstacle.hpp"
#include "duck.hpp"
bool colision(SDL_Rect *r, SDL_Rect *rr);
float lerp(float a, float b, float f);
extern double ticks;

class Mestre{
    private:
        SDL_Texture *img;
        int hspd=0;
        int vspd=0;
        SDL_RendererFlip flip=SDL_FLIP_NONE;
        SDL_Point center={8, 14};
    public:
        Mestre(SDL_Renderer *renderer, int x, int y);
        void draw(SDL_Renderer *renderer);
        void update(Obstacle *obs[], int size, Duck *duck);
        SDL_Rect rect={0, 0, 16, 16};
};

#endif