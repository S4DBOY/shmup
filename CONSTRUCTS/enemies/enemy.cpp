#include "enemy.h"

#include <cmath>
#include "../../BASIC/globals.h"
#include "../managers.h"

void Enemy::GetVectorToPlayer(double x, double y, double &vectorX, double &vectorY)
{
    double playerX=0, playerY=0;
    playerManager->GetPlayerLocation(playerX, playerY);
    vectorX=playerX-x; vectorY=playerY-y;
}

double Enemy::GetAngleToPlayer(double x, double y)
{
    double vectorX=0, vectorY=0;
    GetVectorToPlayer(x, y, vectorX, vectorY);
    return atan2(vectorY, vectorX)*(180/M_PI);
}

void Enemy::Draw()
{
    SDL_Rect a={int(x)-100, int(y)-35, int(200*(health/3000.0)), 5};
    SDL_RenderFillRect(ren, &a);
    a.w=200; SDL_RenderDrawRect(ren, &a);

    loc.x=x-50/2; loc.y=y-50/2;
    SDL_RenderFillRect(ren, &loc);
}
