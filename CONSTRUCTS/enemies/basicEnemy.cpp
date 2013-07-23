#include "basicEnemy.h"

#include "../../BASIC/globals.h"
#include "../../CONSTRUCTS/managers.h"

BasicEnemy::BasicEnemy(int ntype, double nx, double ny, double nvx, double nvy):
    Enemy(ntype, nx, ny, nvx, nvy)
{
    loc.w=50; loc.h=50;
    maxHealth=3000;
    health=maxHealth;
}

void BasicEnemy::Logic()
{
    double a=(frameCounter/10)%360;
    double basev=2;
    if(frameCounter%20==0)
    {
        int a=107; int a1=40; int a2=1;
        for(int i=0;i<30;++i)
        {
            bulletManager.AddBasicBullet(B_BULLET1, 1, a, y, basev, 90); a+=a1; a1-=a2;
        }
    }
        /*for(int i=0;i<360;i+=15)
        {
            bulletManager.AddComplexBullet(B_BULLET1, 1, x, y, basev, i-a, 0, 0);
            bulletManager.AddBulletData(45, BULLET_ANGULAR_VELOCITY, SET, 5);
            bulletManager.AddBulletData(45, BULLET_ACCEL, SET, -0.7);
            bulletManager.AddBulletData(55, BULLET_ANGULAR_VELOCITY, SET, 0);
            bulletManager.AddBulletData(55, BULLET_ACCEL, SET, 0);

            bulletManager.AddComplexBullet(B_BULLET1, 1, x, y, basev, i+a, 0, 0);
            bulletManager.AddBulletData(45, BULLET_ANGULAR_VELOCITY, SET, -5);
            bulletManager.AddBulletData(45, BULLET_ACCEL, SET, -0.7);
            bulletManager.AddBulletData(55, BULLET_ANGULAR_VELOCITY, SET, 0);
            bulletManager.AddBulletData(55, BULLET_ACCEL, SET, 0);
        }*/
    /*double angle=GetAngleToPlayer(x, y);
    if(frameCounter%120==0)
        for(int i=-3;i<=3;i+=1)
            bulletManager.AddBasicBullet(B_BULLET1, x, y, basev, angle+i);*/
}
