#include "../../RESOURCES/images.h"

#include "bullet.h"


Bullet::Bullet(int ntype, double nx, double ny, double nvx, double nvy):
    type(ntype), x(nx), y(ny), vx(nvx), vy(nvy)
{
    source.x=0; source.y=112; source.w=16; source.h=16;
    loc.x=x-32/2; loc.y=y-32/2;
    loc.w=32; loc.h=32;
    angle=atan2(vy, vx)*(180/M_PI)+90;
}

void Bullet::SetDamage(int n_damage)
{
    damage=n_damage;
}

void Bullet::SetTiming(int n_delay, int n_lifetime)
{
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
    if(y>SCREEN_HEIGHT+100|| y<-200 || x<-100 || x>SCREEN_WIDTH+80) return 1;
    if(lifetime!=0 && time>lifetime) return 1;
    return 0;
};

int Bullet::IsEnemyHit(SDL_Rect *r)
{
    if(time<=delay) return 0;
    if(SDL_HasIntersection(r, &loc)) return damage;
    return 0;
};


void Bullet::Draw()
{
    if(time<=delay) return;
    loc.x=x-32/2; loc.y=y-32/2;
    SDL_RenderCopyEx(ren, bulletSheet, &source, &loc, angle, NULL, SDL_FLIP_NONE);

    SDL_RenderDrawRect(ren, &loc);
};
