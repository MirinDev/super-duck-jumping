#include "duck.hpp"


Duck::Duck(SDL_Renderer *renderer, int x, int y){
    SDL_Surface *tmp=IMG_ReadXPMFromArray(icon_xpm);
    img=SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);
    
    rect.x=x;
    rect.y=y;
}

void Duck::draw(SDL_Renderer *renderer){
    SDL_RenderCopyEx(renderer, img, NULL, &rect, cos(ticks)*16, &center, flip);
}

void Duck::update(Obstacle *obs[], int size){
    if(left){
        hspd-=spd;
    }
    if(right){
        hspd+=spd;
    }
    if(vspd<8){
        vspd+=1;
    }

    if(hspd<0){
        flip=SDL_FLIP_HORIZONTAL;
        center.x=20;
    }
    if(hspd>0){
        flip=SDL_FLIP_NONE;
        center.x=12;
    }
    
    SDL_Rect hc={rect.x+hspd, rect.y, rect.w, rect.h};
    SDL_Rect vc={rect.x, rect.y+vspd, rect.w, rect.h};

    for(int i=1; i<size; i++){
        if(colision(&rect, &obs[i]->rect)){
            game=false;
        }
    }

    if(colision(&hc, &obs[0]->rect)){
        if(hspd>0){
            rect.x=obs[0]->rect.x-rect.w;
        }
        if(hspd<0){
            rect.x=obs[0]->rect.x+obs[0]->rect.w;
        }
        hspd=0;
    }
    if(colision(&vc, &obs[0]->rect)){
        if(vspd>0){
            rect.y=obs[0]->rect.y-rect.h;
            down=true;
        }
        if(vspd<0){
            rect.y=obs[0]->rect.y+obs[0]->rect.h;
        }
        if(vspd>0 && jump){
            vspd=-16;
            jump=false;
            down=false;
        }else{
            vspd=0;
        }
    }
    rect.x+=hspd;
    rect.y+=vspd;
    
    hspd=0;
}

void Duck::keyd(SDL_Keycode  key){
    if(key==SDLK_a){
        left=true;
    }
    if(key==SDLK_d){
        right=true;
    }
    if(key==SDLK_SPACE){
        if(!pjump && down){
            jump=true;
        }
        pjump=true;
    }
}

void Duck::keyu(SDL_Keycode key){
    if(key==SDLK_a){
        left=false;
    }
    if(key==SDLK_d){
        right=false;
    }
    if(key==SDLK_SPACE){
        pjump=false;
    }
}