#include "enemy.h"

#include "../playerManager.h"
#include "../../RESOURCES/images.h"

#include <cmath>
#define M_PI		3.14159265358979323846

Enemy::Enemy(int ntype, double nx, double ny, double nvx, double nvy):
            type(ntype), x(nx), y(ny), vx(nvx), vy(nvy)
{
    graphic.setSize(sf::Vector2f{50, 50});
    graphic.setOrigin(50/2, 50/2);
    graphic.setFillColor(sf::Color::White);

    lifebar.setSize(sf::Vector2f{200, 5});
    lifebar.setFillColor(sf::Color::Black);
    lifebar.setOutlineColor(sf::Color::White);
    lifebar.setOutlineThickness(1);
}

void Enemy::GetVectorToPlayer(double x, double y, double &vectorX, double &vectorY)
{
    double playerX=0, playerY=0;
    playerManager.GetPlayerLocation(playerX, playerY);
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
    DrawRect(graphic, x, y);

    DrawRect(lifebar, x-100, y-35);
    life.setSize(sf::Vector2f((200*health)/maxHealth, 5));
    DrawRect(life, x-100, y-35);
}
