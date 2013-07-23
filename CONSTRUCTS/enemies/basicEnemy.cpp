#include "basicEnemy.h"

#include "../../BASIC/globals.h"
#include "../../CONSTRUCTS/managers.h"

BasicEnemy::BasicEnemy(int ntype, double nx, double ny, double nvx, double nvy):
    Enemy(ntype, nx, ny, nvx, nvy)
{
    loc.w=50; loc.h=50;
    health=3000;
}

void BasicEnemy::Logic()
{
    double a=(frameCounter/10)%360;
    double basev=2;
    if(frameCounter%20==0)
    {
        int a=100; int a1=40; int a2=1;
        for(int i=0;i<30;++i)
        {
            bulletManager.AddEnemyBullet(B_BULLET1, a, y, basev, 90); a+=a1; a1-=a2;
        }
    }
        /*for(int i=0;i<360;i+=15)
        {
            bulletManager->AddEnemyComplexBullet(B_BULLET1, x, y, basev, i-a, 0, 0);
            bulletManager->AddEnemyBulletData(45, BULLET_ANGULAR_VELOCITY, SET, 5);
            bulletManager->AddEnemyBulletData(45, BULLET_ACCEL, SET, -0.7);
            bulletManager->AddEnemyBulletData(55, BULLET_ANGULAR_VELOCITY, SET, 0);
            bulletManager->AddEnemyBulletData(55, BULLET_ACCEL, SET, 0);

            bulletManager->AddEnemyComplexBullet(B_BULLET1, x, y, basev, i+a, 0, 0);
            bulletManager->AddEnemyBulletData(45, BULLET_ANGULAR_VELOCITY, SET, -5);
            bulletManager->AddEnemyBulletData(45, BULLET_ACCEL, SET, -0.7);
            bulletManager->AddEnemyBulletData(55, BULLET_ANGULAR_VELOCITY, SET, 0);
            bulletManager->AddEnemyBulletData(55, BULLET_ACCEL, SET, 0);
        }*/
    /*double angle=GetAngleToPlayer(x, y);
    if(frameCounter%120==0)
        for(int i=-3;i<=3;i+=1)
            bulletManager->AddEnemyBullet(B_BULLET1, x, y, basev, angle+i);*/
}
