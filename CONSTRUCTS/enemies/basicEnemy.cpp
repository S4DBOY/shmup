#include "basicEnemy.h"

#include "../../CONSTRUCTS/managers.h"
#include <cmath>

BasicEnemy::BasicEnemy(int ntype, double nx, double ny, double nvx, double nvy):
    Enemy(ntype, nx, ny, nvx, nvy)
{
    loc.w=50; loc.h=50;
    health=1000;
}

BasicEnemy::~BasicEnemy()
{
    //dtor
}

void BasicEnemy::Move()
{
    x+=vx;
    y+=vy;
    if(x>SCREEN_WIDTH || x<0) vx=-vx;
}

void BasicEnemy::Logic()
{
    double a=0, b=0;//double a=rand()%360, b=rand()%360;
    double basev=2;
    if(frameCounter%30==0)
    for(int i=0;i<360;i+=10)
    {
        bulletManager->AddEnemyComplexBullet(B_BULLET1, x, y, basev, i+a, 0, 0, 0);
        //bulletManager->AddEnemyBulletData(45, 0, 0, 5, -0.7);
        //bulletManager->AddEnemyBulletData(55, 0, 0, 0.0001, 0.0001);
        bulletManager->AddEnemyComplexBullet(B_BULLET1, x, y, basev, i+b, 0, 0, 0);
        //bulletManager->AddEnemyBulletData(45, 0, 0, -5, -0.7);
        //bulletManager->AddEnemyBulletData(55, 0, 0, 0.0001, 0.0001);
    }
}

void BasicEnemy::Draw()
{
    SDL_Rect a={int(x)-50, int(y)-35, int(100*(health/1000.0)), 5};
    SDL_RenderFillRect(ren, &a);
    a.w=100; SDL_RenderDrawRect(ren, &a);

    loc.x=x-50/2; loc.y=y-50/2;
    SDL_RenderFillRect(ren, &loc);
}
