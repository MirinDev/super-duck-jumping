// Aqui vc importa as libs do pato
#include <duck.hpp>

// aqui eu defino as variaveis base do pato
Duck::Duck(SDL_Renderer *renderer, int x, int y){
    img=IMG_LoadTexture(renderer, "res/duck.png");
    g=new Ganxo(0, 0);
    
    rect.x=x;
    rect.y=y;
}

void Duck::draw(SDL_Renderer *renderer){
    SDL_RenderCopyEx(renderer, img, NULL, &rect, cos(ticks)*16, &center, flip);
    g->draw(renderer);
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
    for(int i=0; i<size; i++){
        if(colision(&hc, &obs[i]->rect)){
            if(hspd>0){
                rect.x=obs[i]->rect.x-rect.w;
            }
            if(hspd<0){
                rect.x=obs[i]->rect.x+obs[i]->rect.w;
            }
            hspd=0;
            if(action){
                vspd=-4;
            }
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
            if(vspd>0 && jump){
                vspd=-16;
                jump=false;
            }else{
                vspd=0;
            }
        }
    }
    rect.y+=vspd;

    g->set(rect.x, rect.y);
    g->update(obs, size);
    if(ga){
        g->attack(&rect);
        ga=false;
    }
    hspd=0;

    if(g->push){
        hspd=lerp(rect.x, g->rect.x+g->point.x, 0.2)-rect.x;
        vspd=lerp(rect.y, g->rect.y+g->point.y, 0.2)-rect.y;
        g->point.x=lerp(g->point.x, 0, 0.2);
        g->point.y=lerp(g->point.y, 0, 0.2);
        if(g->point.x==0 && g->point.y==0){
            g->push=false;
        }
    }
}

void Duck::keyd(SDL_Keycode  key){
    if(key==SDLK_LEFT || key==SDLK_a){
        left=true;
    }
    if(key==SDLK_RIGHT || key==SDLK_d){
        right=true;
    }
    if(key==SDLK_c || key==SDLK_SPACE){
        if(!pjump){
            jump=true;
        }
        pjump=true;
    }
    if(key==SDLK_z || key==SDLK_LSHIFT){
        action=true;
    }
}

void Duck::keyu(SDL_Keycode key){
    if(key==SDLK_LEFT || key==SDLK_a){
        left=false;
    }
    if(key==SDLK_RIGHT || key==SDLK_d){
        right=false;
    }
    if(key==SDLK_c || key==SDLK_SPACE){
        pjump=false;
        jump=false;
    }
    if(key==SDLK_z || key==SDLK_LSHIFT){
        action=false;
    }
}

void Duck::moused(int x, int y){
    if(!pga){
        ga=true;
    }
    pga=true;
    g->mx=x;
    g->my=y;
}

void Duck::mouseu(){
    ga=false;
    pga=false;
}
