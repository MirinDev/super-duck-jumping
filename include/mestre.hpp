#ifndef MESTRE_HPP
#define MESTRE_HPP
#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "piriquitin_image.h"

class Mestre{
    private:
        SDL_Texture *img;
    public:
        Mestre(SDL_Renderer *renderer, int x, int y);
        void draw(SDL_Renderer *renderer);
        SDL_Rect rect={0, 0, 16, 16};
};

#endif