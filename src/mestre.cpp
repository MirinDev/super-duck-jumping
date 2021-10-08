#include "mestre.hpp"

Mestre::Mestre(SDL_Renderer *renderer, int x, int y){
    SDL_Surface *tmp=IMG_ReadXPMFromArray(piriquitin);
    img=SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);
    
    rect.x=x;
    rect.y=y;
}

void Mestre::draw(SDL_Renderer *renderer){
    SDL_RenderCopyEx(renderer, img, NULL, &rect, sin(ticks)*16, &center, flip);
}

void Mestre::update(Obstacle *obs[], int size, Duck *duck){
    if(vspd<8){
        vspd+=1;
    }
    hspd=lerp(rect.x, duck->rect.x, 0.1)-rect.x;
    if(hspd<0){
        flip=SDL_FLIP_HORIZONTAL;
    }
    if(hspd>0){
        flip=SDL_FLIP_NONE;
    }

    SDL_Rect hc={rect.x+hspd, rect.y, rect.w, rect.h};
    for(int i=1; i<size; i++){
        if(colision(&hc, &obs[i]->rect)){
            if(hspd>0){
                rect.x=obs[i]->rect.x-rect.w;
            }
            if(hspd<0){
                rect.x=obs[i]->rect.x+obs[i]->rect.w;
            }
            hspd=0;
            vspd=-4;
        }
    }
    rect.x+=hspd;

    SDL_Rect vc={rect.x, rect.y+vspd, rect.w, rect.h};
    for(int i=0; i<size; i++){
        if(colision(&vc, &obs[i]->rect)){
            if(vspd>0){
                rect.y=obs[i]->rect.y-rect.h;
            }
            if(vspd<0){
                rect.y=obs[i]->rect.y+obs[i]->rect.h;
            }
            vspd=0;
        }
    }
    rect.y+=vspd;
}