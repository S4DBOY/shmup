#include "basicEnemy.h"

#include "../../BASIC/globals.h"
#include "../../CONSTRUCTS/bulletManager.h"

BasicEnemy::BasicEnemy(int ntype, double nx, double ny, double nvx, double nvy):
    Enemy(ntype, nx, ny, nvx, nvy)
{
    maxHealth=3000;
    health=maxHealth;
}

void BasicEnemy::Logic()
{
    double a=(frameCounter/10)%360;
    double basev=4;
    if(frameCounter%20==1)
    {
        for(int i=0;i<360;i+=15)
        {
            bulletManager.AddComplexBullet("B_BULLET1", 1, x, y, basev, i-a, 0, 0);
            bulletManager.AddBulletData(45, BULLET_ANGULAR_VELOCITY, SET, 5);
            bulletManager.AddBulletData(45, BULLET_ACCEL, SET, -0.1);
            bulletManager.AddBulletData(55, BULLET_ANGULAR_VELOCITY, SET, 0);
            bulletManager.AddBulletData(55, BULLET_ACCEL, SET, 0);

            bulletManager.AddComplexBullet("B_BULLET1", 1, x, y, basev, i+a, 0, 0);
            bulletManager.AddBulletData(45, BULLET_ANGULAR_VELOCITY, SET, -5);
            bulletManager.AddBulletData(45, BULLET_ACCEL, SET, -0.1);
            bulletManager.AddBulletData(55, BULLET_ANGULAR_VELOCITY, SET, 0);
            bulletManager.AddBulletData(55, BULLET_ACCEL, SET, 0);
        }
    }
    double angle=GetAngleToPlayer(x, y);
    if(frameCounter%120==0)
        for(int i=-3;i<=3;i+=1)
            bulletManager.AddBasicBullet("B_BULLET1", 1, x, y, basev, angle+i);
}
