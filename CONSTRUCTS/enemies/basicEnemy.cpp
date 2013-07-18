#include "basicEnemy.h"

#include "../../CONSTRUCTS/managers.h"
#include <cmath>

BasicEnemy::BasicEnemy(int ntype, double nx, double ny, double nvx, double nvy):
    Enemy(ntype, nx, ny, nvx, nvy)
{
    loc.w=50; loc.h=50;
    health=3000;
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
    double a=(frameCounter/10)%360;
    double basev=4;
    if(frameCounter%20==0)
        for(int i=0;i<360;i+=15)
        {
            bulletManager->AddEnemyComplexBullet(B_BULLET1, x, y, basev, i-a, 0, 0, 0);
            bulletManager->AddEnemyBulletData(45, BULLET_ANGULAR_VELOCITY, SET, 5);
            bulletManager->AddEnemyBulletData(45, BULLET_ACCEL, SET, -0.7);
            bulletManager->AddEnemyBulletData(55, BULLET_ANGULAR_VELOCITY, SET, 0);
            bulletManager->AddEnemyBulletData(55, BULLET_ACCEL, SET, 0);

            bulletManager->AddEnemyComplexBullet(B_BULLET1, x, y, basev, i+a, 0, 0, 0);
            bulletManager->AddEnemyBulletData(45, BULLET_ANGULAR_VELOCITY, SET, -5);
            bulletManager->AddEnemyBulletData(45, BULLET_ACCEL, SET, -0.7);
            bulletManager->AddEnemyBulletData(55, BULLET_ANGULAR_VELOCITY, SET, 0);
            bulletManager->AddEnemyBulletData(55, BULLET_ACCEL, SET, 0);
        }
    double angle=GetAngleToPlayer();
    if(frameCounter%120==0)
        for(int i=-3;i<=3;i+=1)
            bulletManager->AddEnemyBullet(B_BULLET1, x, y, basev, angle+i);
}

void BasicEnemy::Draw()
{
    SDL_Rect a={int(x)-100, int(y)-35, int(200*(health/3000.0)), 5};
    SDL_RenderFillRect(ren, &a);
    a.w=200; SDL_RenderDrawRect(ren, &a);

    loc.x=x-50/2; loc.y=y-50/2;
    SDL_RenderFillRect(ren, &loc);
}
