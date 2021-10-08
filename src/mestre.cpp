#include "mestre.hpp"

Mestre::Mestre(SDL_Renderer *renderer, int x, int y){
    SDL_Surface *tmp=IMG_ReadXPMFromArray(piriquitin);
    img=SDL_CreateTextureFromSurface(renderer, tmp);
    
    rect.x=x;
    rect.y=y;
}

void Mestre::draw(SDL_Renderer *renderer){
    SDL_RenderCopy(renderer, img, NULL, &rect);
}