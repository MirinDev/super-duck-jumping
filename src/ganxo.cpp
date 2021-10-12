#include "ganxo.hpp"

Ganxo::Ganxo(int sx, int sy){
    rect.x=sx;
    rect.y=sy;
}

void Ganxo::draw(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.x+point.x, rect.y+point.y);
}

void Ganxo::update(Obstacle *obs[], int size){
    if(on){
        if(f==SDL_FLIP_NONE){
            point.x+=8;
        }
        if(f==SDL_FLIP_HORIZONTAL){
            point.x-=8;
        }
        if(sqrt(point.x*point.x+point.y*point.y)>240){
            on=false;
            point.x=0;
        }

        SDL_Rect r={rect.x+point.x, rect.y+point.y,1, 1};
        for(int i=0; i<size; i++){
            if(colision(&r, &obs[i]->rect)){
                on=false;
                push=true;
            }
        }
    }
}

void Ganxo::set(int sx, int sy){
    rect.x=sx+8;
    rect.y=sy;
}

void Ganxo::attack(SDL_RendererFlip flip){
    if(!on){
        f=flip;
        point.x=0;
    }
    on=true;
}