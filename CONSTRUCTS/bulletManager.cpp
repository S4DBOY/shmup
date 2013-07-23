#include "managers.h"

#include "../CONSTRUCTS/bullets/basicBullet.h"
#include "../CONSTRUCTS/bullets/acceleratingBullet.h"
#include "../CONSTRUCTS/bullets/acceleratingBulletXY.h"
#include "../CONSTRUCTS/bullets/complexBullet.h"
#include "../RESOURCES/images.h"

BulletManager bulletManager;

BulletManager::BulletManager()
{
    enemyBullets.reserve(10000);
    playerBullets.reserve(10000);
}

BulletManager::~BulletManager()
{
    enemyBullets.clear();
    playerBullets.clear();
}

void BulletManager::Move()
{
    for(unsigned int i=0; i<enemyBullets.size(); ++i) {enemyBullets[i]->Move();}
    for(unsigned int i=0; i<playerBullets.size(); ++i) {playerBullets[i]->Move();}
}

void BulletManager::Logic()
{
    for(unsigned int i=0; i<enemyBullets.size(); ++i)
    {
        if(enemyBullets[i]->CheckBounds()) {enemyBullets.erase(enemyBullets.begin()+i); i=i-1;}
    }
    for(unsigned int i=0; i<playerBullets.size(); ++i)
    {
        if(playerBullets[i]->CheckBounds()) {playerBullets.erase(playerBullets.begin()+i); i=i-1;}
    }
}

void BulletManager::Draw()
{
    SDL_SetTextureAlphaMod(bulletSheet, 128);
    for(unsigned int i=0; i<playerBullets.size(); ++i){ playerBullets[i]->Draw();}
    SDL_SetTextureAlphaMod(bulletSheet, 255);
    for(unsigned int i=0; i<enemyBullets.size(); ++i){ enemyBullets[i]->Draw();}
}

int BulletManager::IsEnemyHit(SDL_Rect loc)
{
    int change,damage=0;
    for(unsigned int i=0; i<playerBullets.size(); ++i)
    {
        change=playerBullets[i]->IsRectHit(loc);
        damage+=change;
        if(change) {playerBullets.erase(playerBullets.begin()+i); i=i-1;}
    }
    return damage;
}

int BulletManager::IsPlayerHit(double x, double y, double radius)
{
    bool change, damage=0;
    for(unsigned int i=0; i<enemyBullets.size(); ++i)
    {
        change=enemyBullets[i]->IsCircleHit(x, y, radius);
        damage+=change;
        if(change) {enemyBullets.erase(enemyBullets.begin()+i); i=i-1;}
    }
    return damage;
}

void BulletManager::AddBasicBulletXY(int type, int damage,
                                    double x, double y, double vx, double vy)
{
    DetermineOwner().push_back(std::unique_ptr<Bullet>(new BasicBulletXY(type, x, y, vx, vy)));
    if(!(damage-1)) DetermineOwner().back()->SetDamage(damage);
}

void BulletManager::AddBasicBullet(int type, int damage,
                                    double x, double y, double v, double angle)
{
    DetermineOwner().push_back(std::unique_ptr<Bullet>(new BasicBullet(type, x, y, v, angle)));
    if(!(damage-1)) DetermineOwner().back()->SetDamage(damage);
}

void BulletManager::AddAccelBullet(int type, int damage,
                                    double x, double y, double v, double angle, double accel, double minmaxV)
{
    DetermineOwner().push_back(std::unique_ptr<Bullet>(new AcceleratingBullet(type, x, y, v, angle, accel, minmaxV)));
    if(!(damage-1)) DetermineOwner().back()->SetDamage(damage);
}

void BulletManager::AddAccelBulletXY(int type, int damage,
                                    double x, double y, double vx, double vy, double accelX, double accelY,
                                    double minmaxX, double minmaxY)
{
    DetermineOwner().push_back(std::unique_ptr<Bullet>(new AcceleratingBulletXY(type, x, y, vx, vy, accelX, accelY, minmaxX, minmaxY)));
    if(!(damage-1)) DetermineOwner().back()->SetDamage(damage);
}

void BulletManager::AddComplexBullet(int type, int damage,
                                    double x, double y, double v, double angle, double angularV, double accel)
{
    DetermineOwner().push_back(std::unique_ptr<Bullet>(new ComplexBullet(type, x, y, v, angle, angularV, accel)));
    if(!(damage-1)) DetermineOwner().back()->SetDamage(damage);
}

void BulletManager::AddBulletData(int time, int instruction, int setOrChange, double data)
{
    DetermineOwner().back()->AddData(time, instruction, setOrChange, data);
}

void BulletManager::SetBulletTiming(int delay, int lifetime)
{
    DetermineOwner().back()->SetTiming(delay, lifetime);
}

std::vector<std::unique_ptr<Bullet>> &BulletManager::DetermineOwner()
{
    return (!currentOwner) ? playerBullets : enemyBullets;
}

void BulletManager::EraseAllBullets()
{
    enemyBullets.clear();
    playerBullets.clear();
}
