#include "player.h"

#include "../../RESOURCES/images.h"
#include "../../CONSTRUCTS/managers.h"

Player::Player()
{
    x=SCREEN_WIDTH/2;y=SCREEN_HEIGHT-50;
    left=0;right=0;up=0;down=0;
    vx=0;vy=0;
}

Player::~Player()
{
    //dtor
}

void Player::Input()
{
    double v=8;
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
            case SDLK_z: {shooting=0;} break;
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
    if(focus==1) {vx=vx/focusmod; vy=vy/focusmod;}
    if( ( x < 0 ) || ( x > SCREEN_WIDTH ) )  x -= vx;
    if( ( y < 0 ) || ( y > SCREEN_HEIGHT ) ) y -= vy;
}

void Player::Logic()
{
    int v=-32, v1=-28;
    int mod=!focus;
    if((shooting==1) && (frameCounter%4==1))
    {
        bulletManager->AddPlayerBullet(B_BULLET1, x+10, y, 0, v, 5);
        bulletManager->AddPlayerBullet(B_BULLET1, x-10, y, 0, v, 5);

            bulletManager->AddPlayerBullet(B_BULLET1, x+30, y, 5*mod-2, v1, 2);
        bulletManager->AddPlayerBullet(B_BULLET1, x-30, y, -5*mod+2, v1, 2);
        bulletManager->AddPlayerBullet(B_BULLET1, x+30, y, 10*mod-4, v1, 2);
        bulletManager->AddPlayerBullet(B_BULLET1, x-30, y, -10*mod+4, v1, 2);
    }
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
    SDL_Rect loc={int(x)-32, int(y)-48, 64, 96};
    SDL_Rect source={0, 0, 32, 48};
    SDL_RenderCopy(ren, imgplayer, &source, &loc);

}
