#include <stdio.h>
#include "SDL2/SDL.h"

#include "duck.hpp"
#include "obstacle.hpp"
#include "mestre.hpp"
#include "kk.h"
double ticks=0;
bool game=true;

bool colision(SDL_Rect *r, SDL_Rect *rr){
    return(r->x<rr->x+rr->w && r->x+r->w>rr->x && r->y<rr->y+rr->h && r->y+r->h>rr->y);
}

int main(){
    //basic progam
    SDL_Window *window=SDL_CreateWindow("duck", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer=SDL_CreateRenderer(window, 0, 0);
    SDL_Event event;
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    Uint32 fps=1000/60;
    bool full=false;

    //game variables
    Duck *duck=new Duck(renderer, 32, 320);
    Mestre *m=new Mestre(renderer, 32, 320);
    Obstacle *obs[]={
        (new Obstacle(0, 352, 600, 58)),
        
        (new Obstacle(128, 320, 32, 32)),
        (new Obstacle(320, 320, 32, 32))
    };
    
    SDL_Surface *tmpo=IMG_ReadXPMFromArray(kk);
    SDL_Texture *image=SDL_CreateTextureFromSurface(renderer, tmpo);
    while(game){
        Uint32 start=SDL_GetTicks();

        //events
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT){
                game=false;
            }
            if(event.type==SDL_KEYUP && event.key.keysym.sym==SDLK_F11){
                if(full){
                    SDL_SetWindowFullscreen(window, 0);
                }else{
                    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                }
                full=!full;
            }
            if(event.type==SDL_KEYDOWN){
                duck->keyd(event.key.keysym.sym);
            }
            if(event.type==SDL_KEYUP){
                duck->keyu(event.key.keysym.sym);
            }
        }

        //draw
        SDL_RenderSetLogicalSize(renderer, 600, 400);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, image, NULL, NULL);

        duck->draw(renderer);
        m->draw(renderer);
        int size=sizeof(obs)/sizeof(*obs);
        duck->update(obs, size);

        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
        for(int i=0; i<size; i++){
            if(i>0){
                SDL_SetRenderDrawColor(renderer, 200, 200, 0, 255);
                //obs[i]->update();
            }
            obs[i]->draw(renderer);
        }

        SDL_RenderPresent(renderer);

       
        ticks+=0.1;
        //fixed fps
        Uint32 time=(SDL_GetTicks()-start);
        if(time<fps){
            SDL_Delay(time+fps);
        }
    }

    SDL_Quit();
    return 0;
}

int WinMain(){
    return main();
}
