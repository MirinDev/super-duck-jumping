#ifndef DUCK_HPP
#define DUCK_HPP
#include <stdio.h>
#include <math.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "obstacle.hpp"
extern double ticks;
extern bool game;
bool colision(SDL_Rect *r, SDL_Rect *rr);

class Duck{
    private:
        SDL_Point center={12, 26};
        SDL_Rect rect={0, 0, 32, 32};
        SDL_Texture *img;
        int spd=6;
        int hspd=0;
        int vspd=0;

        bool left=false;
        bool right=false;
        bool pjump=false;
        bool jump=false;

        bool down=false;
    public:
        Duck(SDL_Renderer *renderer, int x, int y);
        void draw(SDL_Renderer *renderer);
        void update(Obstacle *obs[], int size);
        void keyd(SDL_Keycode key);
        void keyu(SDL_Keycode key);
};

#endif
