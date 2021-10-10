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

void Ganxo::set(int sx, int sy){
    rect.x=sx+8;
    rect.y=sy;
}

void Ganxo::keyd(SDL_Keycode key){
    if(key==SDLK_LEFT){
        if(!pleft){
            mode=0;
        }
        pleft=true;
    }
    if(key==SDLK_RIGHT){
        if(!pright){
            mode=1;
        }
        pright=true;
    }
}
void Ganxo::keyu(SDL_Keycode key){
    if(key==SDLK_LEFT){
        pleft=false;
    }
    if(key==SDLK_RIGHT){
        pright=false;
    }
}