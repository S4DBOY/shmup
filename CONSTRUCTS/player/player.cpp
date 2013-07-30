#include "player.h"

#include "../../BASIC/globals.h"
#include "../../RESOURCES/images.h"
#include "../../CONSTRUCTS/bulletManager.h"

Player::Player()
{
    x=SCREEN_WIDTH/2;y=SCREEN_HEIGHT-50;
    left=0;right=0;up=0;down=0;
    vx=0;vy=0;

    hitboxRadius=2;
}

Player::~Player()
{
    //dtor
}

void Player::Input()
{
    double v=6;
    if( event.type == sf::Event::KeyPressed )
    {
        switch( event.key.code)
       {
            case sf::Keyboard::Z: {shooting=1;} break;
            case sf::Keyboard::LShift: {focus=1;} break;
            case sf::Keyboard::Left:     {vx =- v; left=1;} break;
            case sf::Keyboard::Right:    {vx = v; right=1;} break;
            case sf::Keyboard::Up:       {vy =- v; up=1;} break;
            case sf::Keyboard::Down:     {vy = v; down=1;} break;
            default: ;
       }
    }
    if( event.type == sf::Event::KeyReleased )
    {
        switch( event.key.code )
        {
            case sf::Keyboard::Z: {shooting=0;shootingCounter=0;} break;
            case sf::Keyboard::LShift: {focus=0;} break;
            case sf::Keyboard::Left:     {left=0; if(right==1) vx=v; else vx = 0;} break;
            case sf::Keyboard::Right:    {right=0; if(left==1)vx=-v; else vx = 0;} break;
            case sf::Keyboard::Up:       {up=0; if(down==1) vy=v; else vy = 0;} break;
            case sf::Keyboard::Down:     {down=0; if(up==1) vy=-v; else vy = 0;}; break;
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
        bulletManager.AddBasicBulletXY("B_BULLET1_P", 5, x+10, y, 0, v);
        bulletManager.AddBasicBulletXY("B_BULLET1_P", 5, x-10, y, 0, v);

        bulletManager.AddBasicBulletXY("B_BULLET1_P", 2, x+50, y-40, 5*mod-2, v1);
        bulletManager.AddBasicBulletXY("B_BULLET1_P", 2, x-50, y-40, -5*mod+2, v1);
        bulletManager.AddBasicBulletXY("B_BULLET1_P", 2, x+80, y+20, 10*mod-4, v1);
        bulletManager.AddBasicBulletXY("B_BULLET1_P", 2, x-80, y+20, -10*mod+4, v1);
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
        float a=(frameCounter%180)*2;
        DrawSprite("HITBOX", x, y, a);
        DrawSprite("HITBOX", x, y, -a);
    }
}

void Player::Draw()
{
    DrawSprite("PLAYER", x, y);

    DrawSprite("YINYANGOPTION", x-80, y+20);
    DrawSprite("YINYANGOPTION", x+80, y+20);
    DrawSprite("YINYANGOPTION", x-50, y-40);
    DrawSprite("YINYANGOPTION", x+50, y-40);
}
