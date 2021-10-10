#ifndef GANXO_HPP
#define GANXO_HPP
#include <stdio.h>
#include <math.h>
#include "SDL2/SDL.h"

class Ganxo{
    private:
        SDL_Rect rect={0, 0, 16, 8};
        int x=0;
        int y=0;
        bool down=false;
    public:
        Ganxo(int x, int y);
        void draw(SDL_Renderer *renderer);
        void set(int x, int y);
        void update();
        void key(SDL_Keycode key);

        double r;
};


#endif