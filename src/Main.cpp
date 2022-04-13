#include <config.h>

#include <stdio.h>


#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/html5.h>
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <duck.hpp>
#include <obstacle.hpp>
#include <mestre.hpp>
double ticks=0;
bool game=true;

bool colision(SDL_Rect *r, SDL_Rect *rr){
    return(r->x<rr->x+rr->w && r->x+r->w>rr->x && r->y<rr->y+rr->h && r->y+r->h>rr->y);
}
float lerp(float a, float b, float f){
    return a+f*(b-a);
}

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event event;

Uint32 fps=1000/60;
SDL_Rect back={0, 0, WIDTH, HEIGHT};
Duck *duck;
Mestre *m;
Obstacle *obs[6];

SDL_Texture *image;

void gameLoop(){
    Uint32 start=SDL_GetTicks();

    //events

    while(SDL_PollEvent(&event)){
        if(event.type==SDL_QUIT){
            game=false;
        }
        if(event.type==SDL_KEYDOWN){
            duck->keyd(event.key.keysym.sym);
        }
        if(event.type==SDL_KEYUP){
            duck->keyu(event.key.keysym.sym);
        }
        if(event.type==SDL_MOUSEBUTTONDOWN && event.button.button==SDL_BUTTON_LEFT){
            duck->moused(event.button.x, event.button.y);
        }
        if(event.type==SDL_MOUSEBUTTONUP){
            duck->mouseu();
        }

        //if(evt.type==SDL_FINGERDOWN){
        //    SDL_Touch *state=SDL_GetTouch(evt.tfinger.touchId);
        //}
    }

    //draw
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, image, NULL, &back);

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

int main(int argc, char *argv[]){
    //basic progam
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    
    window=SDL_CreateWindow("duck", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    //SDL_ShowCursor(0);

    //game variables
    duck=new Duck(renderer, 32, 320);
    m=new Mestre(renderer, 32, 320);
    obs[0]=new Obstacle(0, 352, 600, 58);
    obs[1]=new Obstacle(128, 320, 32, 32);
    obs[2]=new Obstacle(320, 320, 32, 32);
    obs[3]=new Obstacle(384, 160, 32, 96);
    obs[4]=new Obstacle(416, 224, 96, 32);
    obs[5]=new Obstacle(0, 128, 320, 32);

    image=IMG_LoadTexture(renderer, "res/kk.png");

    #ifdef __EMSCRIPTEN__
	emscripten_set_main_loop(gameLoop, 0, 1);
	#else
    while(game){
        gameLoop();
    }
    #endif

    SDL_DestroyWindow(window);
    SDL_Quit();
    IMG_Quit();

    return 0;
}