#include "../../RESOURCES/images.h"

#include "bullet.h"

#include <algorithm>
#include <cmath>

Bullet::Bullet(int ntype, double nx, double ny, double nvx, double nvy):
    type(ntype), x(nx), y(ny), vx(nvx), vy(nvy)
{
    source.x=0; source.y=112; source.w=16; source.h=16;
    loc.x=x-32/2; loc.y=y-32/2;
    loc.w=32; loc.h=32;

    angle=atan2(vy, vx)*(180/M_PI)+90;

    hitbox.w=16; hitbox.h=20;
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
};

bool Bullet::CheckBounds()
{
    if(y>SCREEN_HEIGHT+50|| y<-200 || x<-80 || x>SCREEN_WIDTH+80) return 1;
    if(lifetime!=0 && time>lifetime) return 1;
    return 0;
};

int Bullet::IsEnemyHit(SDL_Rect *r)
{
    if(time<=delay) return 0;

    double t_cos=cos(angle*(M_PI/180)); double t_sin=sin(angle*(M_PI/180));

    dx1=(hitbox.w/2)*t_cos-(hitbox.h/2)*t_sin;
    dx2=(hitbox.w/2)*t_cos+(hitbox.h/2)*t_sin;
    X1=x+dx1; X3=x-dx1; X2=x+dx2; X4=x-dx2;
    int Xmax=std::max(X1, std::max(X2, std::max(X3, X4))); int Xmin=std::min(X1, std::min(X2, std::min(X3, X4)));
    if(r->x+r->w<Xmin) return 0;
    if(r->x>Xmax) return 0;

    dy1=(hitbox.w/2)*t_sin+(hitbox.h/2)*t_cos;
    dy2=(hitbox.w/2)*t_sin-(hitbox.h/2)*t_cos;
    Y1=y+dy1; Y2=y+dy2; Y3=y-dy1; Y4=y-dy2;
    int Ymax=std::max(Y1, std::max(Y2, std::max(Y3, Y4))); int Ymin=std::min(Y1, std::min(Y2, std::min(Y3, Y4)));
    if(r->y+r->h<Ymin) return 0;
    if(r->y>Ymax) return 0;

    Px=X2-X1; Py=Y2-Y1;
    P1=X1*Px+Y1*Py; P2=X2*Px+Y2*Py;
    A1=(r->x)*Px+(r->y)*Py;
    A2=(r->x+r->w)*Px+(r->y)*Py;
    A3=(r->x)*Px+(r->y+r->h)*Py;
    A4=(r->x+r->w)*Px+(r->y+r->h)*Py;
    Amax=std::max(A1, std::max(A2, std::max(A3, A4))); Amin=std::min(A1, std::min(A2, std::min(A3, A4)));
    if(Amax<P1 && Amin<P2) return 0;
    if(Amax>P1 && Amin>P2) return 0;

    Px=X3-X2; Py=Y3-Y2;
    P1=X2*Px+Y2*Py; P2=X3*Px+Y3*Py;
    A1=(r->x)*Px+(r->y)*Py;
    A2=(r->x+r->w)*Px+(r->y)*Py;
    A3=(r->x)*Px+(r->y+r->h)*Py;
    A4=(r->x+r->w)*Px+(r->y+r->h)*Py;
    Amax=std::max(A1, std::max(A2, std::max(A3, A4))); Amin=std::min(A1, std::min(A2, std::min(A3, A4)));
    if(Amax<P1 && Amin<P2) return 0;
    if(Amax>P1 && Amin>P2) return 0;

    return damage;
};


void Bullet::Draw()
{
    if(time<delay) return;
    if(y-loc.h/2>SCREEN_HEIGHT|| y<-loc.h/2 || x<-loc.w/2 || x>SCREEN_WIDTH+loc.w/2) return;
    loc.x=x-32/2; loc.y=y-32/2;
    SDL_RenderCopyEx(ren, bulletSheet, &source, &loc, angle, NULL, SDL_FLIP_NONE);

    /*SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
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
