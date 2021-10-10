#include "config.h"

#include <stdio.h>
#include "SDL2/SDL.h"

#include "duck.hpp"
#include "obstacle.hpp"
#include "mestre.hpp"
#if !USE_IMAGES
#include "kk.h"
#endif
double ticks=0;
bool game=true;

bool colision(SDL_Rect *r, SDL_Rect *rr){
    return(r->x<rr->x+rr->w && r->x+r->w>rr->x && r->y<rr->y+rr->h && r->y+r->h>rr->y);
}
float lerp(float a, float b, float f){
    return a+f*(b-a);
}
int sign(int num){
    if(num<0){
        return -1;
    }else if(num>0){
        return 1;
    }else{
        return 0;
    }
}
SDL_Rect mrect={0, 0, 13, 13};

int main(){
    //basic progam
    SDL_Window *window=SDL_CreateWindow("duck", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer=SDL_CreateRenderer(window, 0, 0);
    SDL_Event event;
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    Uint32 fps=1000/60;
    bool full=false;
    //SDL_ShowCursor(0);

    //game variables
    Duck *duck=new Duck(renderer, 32, 320);
    Mestre *m=new Mestre(renderer, 32, 320);
    Obstacle *obs[]={
        (new Obstacle(0, 352, 600, 58)),
        (new Obstacle(128, 320, 32, 32)),
        (new Obstacle(320, 320, 32, 32)),
        (new Obstacle(384, 160, 32, 96)),
        (new Obstacle(416, 224, 96, 32))
    };
    
    #if !USE_IMAGES
    SDL_Surface *tmpo=IMG_ReadXPMFromArray(kk);
    SDL_Texture *image=SDL_CreateTextureFromSurface(renderer, tmpo);
    SDL_FreeSurface(tmpo);
    #else
    SDL_Texture *image=IMG_LoadTexture(renderer, "res/kk.png");
    #endif

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
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, image, NULL, NULL);

        duck->draw(renderer);
        m->draw(renderer);
        int size=sizeof(obs)/sizeof(*obs);
        duck->update(obs, size);
        m->update(obs, size, duck);

        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
        for(int i=0; i<size; i++){
            //obs[i]->update();
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
