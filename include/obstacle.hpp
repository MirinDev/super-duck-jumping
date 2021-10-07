#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP
#include <stdio.h>
#include <math.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
extern double ticks;

class Obstacle{
    private:
    public:
        SDL_Rect rect={0, 0, 32, 32};
        
        Obstacle(int x, int y, int w, int h);
        void draw(SDL_Renderer *renderer);
        void update();
};

#endif