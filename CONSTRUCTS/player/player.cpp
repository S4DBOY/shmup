#include "player.h"

#include "../../BASIC/globals.h"
#include "../../RESOURCES/images.h"
#include "../../CONSTRUCTS/managers.h"

Player::Player()
{
    x=SCREEN_WIDTH/2;y=SCREEN_HEIGHT-50;
    left=0;right=0;up=0;down=0;
    vx=0;vy=0;
    loc.w=64; loc.h= 96;

    hitboxRadius=2;
}

Player::~Player()
{
    //dtor
}

void Player::Input()
{
    double v=6;
    if( event.type == SDL_KEYDOWN )
    {
        switch( event.key.keysym.sym)
       {
            case SDLK_z: {shooting=1;} break;
            case SDLK_LSHIFT: {focus=1;} break;
            case SDLK_LEFT:     {vx =- v; left=1;} break;
            case SDLK_RIGHT:    {vx = v; right=1;} break;
            case SDLK_UP:       {vy =- v; up=1;} break;
            case SDLK_DOWN:     {vy = v; down=1;} break;
            default: ;
       }
    }
    if( event.type == SDL_KEYUP )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_z: {shooting=0;shootingCounter=0;} break;
            case SDLK_LSHIFT: {focus=0;} break;
            case SDLK_LEFT:     {left=0; if(right==1) vx=v; else vx = 0;} break;
            case SDLK_RIGHT:    {right=0; if(left==1)vx=-v; else vx = 0;} break;
            case SDLK_UP:       {up=0; if(down==1) vy=v; else vy = 0;} break;
            case SDLK_DOWN:     {down=0; if(up==1) vy=-v; else vy = 0;}; break;
            default: ;
        }
    }
}


void Player::Move()
{
    double focusmod=0.4;
    if(focus==1) {vx=vx*focusmod; vy=vy*focusmod;}
    x += vx;
    y += vy;
    if( ( x-8 < 0 ) || ( x+8 > SCREEN_WIDTH ) )  x -= vx;
    if( ( y-8 < 0 ) || ( y+8 > SCREEN_HEIGHT ) ) y -= vy;
    if(focus==1) {vx=vx/focusmod; vy=vy/focusmod;}
}

void Player::Logic()
{
    int v=-32, v1=-28;
    int mod=!focus;
    if((shooting==1 || shootingCounter<1) && (frameCounter%4==0))
    {
        bulletManager.AddBasicBulletXY(B_BULLET1, 5, x+10, y, 0, v);
        bulletManager.AddBasicBulletXY(B_BULLET1, 5, x-10, y, 0, v);

        bulletManager.AddBasicBulletXY(B_BULLET1, 2, x+50, y-40, 5*mod-2, v1);
        bulletManager.AddBasicBulletXY(B_BULLET1, 2, x-50, y-40, -5*mod+2, v1);
        bulletManager.AddBasicBulletXY(B_BULLET1, 2, x+80, y+20, 10*mod-4, v1);
        bulletManager.AddBasicBulletXY(B_BULLET1, 2, x-80, y+20, -10*mod+4, v1);
        shootingCounter=1;
    }
}

void Player::Die()
{
    health=maxHealth;
    x=SCREEN_WIDTH/2;y=SCREEN_HEIGHT-50;
}

void Player::DrawHitBox()
{
    if(focus)
    {
        SDL_Rect loc1={int(x)-64, int(y)-64, 128, 128};
        SDL_Rect source1={0, 16, 64, 64};
        SDL_RenderCopy(ren, effectsSheet, &source1, &loc1);
    }
}

void Player::Draw()
{
    loc.x=int(x)-32; loc.y=int(y)-48;
    SDL_Rect source={0, 0, 32, 48};
    SDL_RenderCopy(ren, imgplayer, &source, &loc);

    SDL_Rect loc1={int(x)-80-16, int(y)+20-16, 32, 32};
    SDL_Rect source1={64, 144, 16, 16};
    SDL_RenderCopy(ren, imgplayer, &source1, &loc1);
    loc1.x=int(x)+80-16; loc1.y=int(y)+20-16;
    SDL_RenderCopy(ren, imgplayer, &source1, &loc1);
    loc1.x=int(x)+50-16; loc1.y=int(y)-40-16;
    SDL_RenderCopy(ren, imgplayer, &source1, &loc1);
    loc1.x=int(x)-50-16; loc1.y=int(y)-40-16;
    SDL_RenderCopy(ren, imgplayer, &source1, &loc1);
}
