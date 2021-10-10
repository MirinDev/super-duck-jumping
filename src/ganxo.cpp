#include "ganxo.hpp"

Ganxo::Ganxo(int x, int y){
    rect.x=x;
    rect.y=y;
}

void Ganxo::draw(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);
    if(down){
        SDL_RenderDrawLine(renderer, rect.x, rect.y, x, y);
    }   
}

void Ganxo::update(){
    
}

void Ganxo::set(int x, int y){
    rect.x=x;
    rect.y=y;
}

void Ganxo::key(SDL_Keycode key){
    if(key==SDLK_c){
        down=true;
    }
}