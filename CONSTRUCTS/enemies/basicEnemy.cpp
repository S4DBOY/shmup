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
    if(frameCounter%60==0)
    {
        bulletManager.AddBasicBullet(B_BULLET1, 1, 632, y+500, 0.8, 90);
        bulletManager.AddBasicBullet(B_BULLET1, 1, 648, y+500, 0.8, 90);
    }
}
