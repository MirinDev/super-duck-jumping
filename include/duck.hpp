#ifndef DUCK_HPP
#define DUCK_HPP
#include <stdio.h>
#include <math.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "config.h"
#include "obstacle.hpp"
#include "ganxo.hpp"
#if !USE_IMAGES
#include "duck_image.h"
#endif
extern double ticks;
extern bool game;
extern SDL_Rect mrect;
bool colision(SDL_Rect *r, SDL_Rect *rr);
float lerp(float a, float b, float f);

class Duck{
    private:
        SDL_Point center={12, 26};
        SDL_Texture *img;
        SDL_RendererFlip flip=SDL_FLIP_NONE;
        Ganxo *g;

        int spd=6;
        int hspd=0;
        int vspd=0;

        bool left=false;
        bool right=false;
        bool pjump=false;
        bool jump=false;

        bool action=false;
        bool ga=false;
        bool pga=false;
    public:
        Duck(SDL_Renderer *renderer, int x, int y);
        void draw(SDL_Renderer *renderer);
        void update(Obstacle *obs[], int size);
        void keyd(SDL_Keycode key);
        void keyu(SDL_Keycode key);

        SDL_Rect rect={0, 0, 32, 32};
};

#endif
