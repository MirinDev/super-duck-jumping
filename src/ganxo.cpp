#include <ganxo.hpp>

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
        point.x=lerp(point.x, s.x, 0.1);
        point.y=lerp(point.y, s.y, 0.1);

        SDL_Rect r={rect.x+point.x, rect.y+point.y, 1, 1};
        for(int i=0; i<size; i++){
            if(colision(&r, &obs[i]->rect)){
                on=false;
                push=true;
            }
        }
        if(sqrt(point.x*point.x+point.y*point.y)>=200){
            on=false;
            point.x=0;
            point.y=0;
        }
    }
}

void Ganxo::set(int sx, int sy){
    rect.x=sx;
    rect.y=sy;
}

void Ganxo::attack(SDL_Rect *re){
    if(!on){
        point.x=0;
        point.y=0;
        r=atan2(my-re->y, mx-re->x);

        s.x=cos(r)*240;
        s.y=sin(r)*240;
    }
    on=true;
}
