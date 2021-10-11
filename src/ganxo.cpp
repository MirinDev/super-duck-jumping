#include "ganxo.hpp"

Ganxo::Ganxo(int sx, int sy){
    rect.x=sx;
    rect.y=sy;
    x=sx;
    y=sy;
}

void Ganxo::draw(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, rect.x, rect.y, x, y);
}

void Ganxo::update(){
    x=rect.x;
    y=rect.y;
    if(mode==0){
        x-=200;
    }
    if(mode==1){
        x+=200;
    }
}

void Ganxo::set(int sx, int sy, SDL_RenderFlip *flip){
    rect.x=sx+8;
    rect.y=sy;
}