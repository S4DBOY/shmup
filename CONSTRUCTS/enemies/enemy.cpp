#include "enemy.h"

#include <cmath>
#include "../../BASIC/globals.h"
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

void Enemy::Draw()
{
    SDL_Rect a={int(x)-100, int(y)-35, int(200*(health/3000.0)), 5};
    SDL_RenderFillRect(ren, &a);
    a.w=200; SDL_RenderDrawRect(ren, &a);

    loc.x=x-50/2; loc.y=y-50/2;
    SDL_RenderFillRect(ren, &loc);
}
