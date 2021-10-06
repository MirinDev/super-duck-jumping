#include "obstacle.hpp"

Obstacle::Obstacle(int x, int y, int w, int h){
    rect.x=x;
    rect.y=y;
    rect.w=w;
    rect.h=h;
}

void Obstacle::draw(SDL_Renderer *renderer){
    SDL_RenderFillRect(renderer, &rect);
}

void Obstacle::update(){
    rect.x-=4;
}