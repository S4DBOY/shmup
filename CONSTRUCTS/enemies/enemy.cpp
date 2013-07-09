#include "enemy.h"

#include <cmath>
#include "../managers.h"

void Enemy::GetVectorToPlayer(double &nx, double &ny)
{
    double px=0, py=0;
    playerManager->GetPlayerLocation(px, py);
    nx=px-x; ny=py-y;
}

double Enemy::GetAngleToPlayer()
{
    double x=0, y=0;
    GetVectorToPlayer(x, y);
    return atan2(-x, y)*(180/M_PI)+90;
}
