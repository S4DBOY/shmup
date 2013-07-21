#include "../../BASIC/globals.h"
#include "../../RESOURCES/images.h"
#include "../../UTILITIES/collision.h"

#include "bullet.h"

#include <cmath>

Bullet::Bullet(int ntype, double nx, double ny, double nvx, double nvy):
    type(ntype), x(nx), y(ny), vx(nvx), vy(nvy)
{
    source.x=0; source.y=112; source.w=16; source.h=16;
    loc.x=x-32/2; loc.y=y-32/2;
    loc.w=32; loc.h=32;

    angle=atan2(vy, vx)*(180/M_PI)+90;

    hitbox.w=12; hitbox.h=20;
}

void Bullet::SetDamage(int n_damage)
{
    damage=n_damage;
}

void Bullet::SetTiming(int n_delay, int n_lifetime)
{
    time=0;
    delay=n_delay;
    lifetime=n_lifetime;
}

void Bullet::Move()
{
    time++;
    if(time<=delay) return;
    x+=vx;
    y+=vy;

    hitbox.x=x-hitbox.w/2; hitbox.y=y-hitbox.h/2;
};

bool Bullet::CheckBounds()
{
    if(y>SCREEN_HEIGHT+50|| y<-200 || x<-80 || x>SCREEN_WIDTH+80) return 1;
    if(lifetime!=0 && time>lifetime) return 1;
    return 0;
};

int Bullet::IsRectHit(SDL_Rect r)
{
    if(time<=delay) return 0;

    if(BoxBox(hitbox, angle, r)) return damage;
    else return 0;
};

int Bullet::IsCircleHit(double Cx, double Cy, double Cr)
{
    if(time<=delay) return 0;

    if(BoxCircle(hitbox, angle, Cx, Cy, Cr)) return damage;
    else return 0;
};

void Bullet::Draw()
{
    if(time<delay) return;
    if(y-loc.h/2>SCREEN_HEIGHT|| y<-loc.h/2 || x<-loc.w/2 || x>SCREEN_WIDTH+loc.w/2) return;
    loc.x=x-32/2; loc.y=y-32/2;
    SDL_RenderCopyEx(ren, bulletSheet, &source, &loc, angle, NULL, SDL_FLIP_NONE);

    /*SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
    double t_cos=cos(angle*(M_PI/180)); double t_sin=sin(angle*(M_PI/180));
    dx1=(hitbox.w/2)*t_cos-(hitbox.h/2)*t_sin;
    dy1=(hitbox.w/2)*t_sin+(hitbox.h/2)*t_cos;
    dx2=(hitbox.w/2)*t_cos+(hitbox.h/2)*t_sin;
    dy2=(hitbox.w/2)*t_sin-(hitbox.h/2)*t_cos;
    X1=x+dx1; Y1=y+dy1; X3=x-dx1; Y3=y-dy1;
    X2=x+dx2; Y2=y+dy2; X4=x-dx2; Y4=y-dy2;
    SDL_RenderDrawLine(ren, X1, Y1, X2, Y2);
    SDL_RenderDrawLine(ren, X2, Y2, X3, Y3);
    SDL_RenderDrawLine(ren, X3, Y3, X4, Y4);
    SDL_RenderDrawLine(ren, X4, Y4, X1, Y1);*/
};
