#include "managers.h"

#include "../CONSTRUCTS/bullets/basicBullet.h"
#include "../CONSTRUCTS/bullets/acceleratingBullet.h"
#include "../CONSTRUCTS/bullets/acceleratingBulletXY.h"
#include "../CONSTRUCTS/bullets/complexBullet.h"

BulletManager *bulletManager;

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
    for(int i=0; i<int(enemyBullets.size()); i++) {enemyBullets[i]->Move();}
    for(int i=0; i<int(playerBullets.size()); i++) {playerBullets[i]->Move();}
}

void BulletManager::Logic()
{
    for(int i=0; i<int(enemyBullets.size()); i++)
    {
        if(enemyBullets[i]->CheckBounds()) {enemyBullets.erase(enemyBullets.begin()+i); i=i-1;}
    }
    for(int i=0; i<int(playerBullets.size()); i++)
    {
        if(playerBullets[i]->CheckBounds()) {playerBullets.erase(playerBullets.begin()+i); i=i-1;}
    }
}

void BulletManager::Draw()
{
    for(int i=0; i<int(playerBullets.size()); i++){ playerBullets[i]->Draw();}
    for(int i=0; i<int(enemyBullets.size()); i++){ enemyBullets[i]->Draw();}
}

int BulletManager::IsEnemyHit(SDL_Rect *loc)
{
    int change,damage=0;
    for(int i=0; i<int(playerBullets.size()); i++)
    {
        change=playerBullets[i]->IsEnemyHit(loc);
        damage+=change;
        if(change) {playerBullets.erase(playerBullets.begin()+i); i=i-1;}
    }
    return damage;
}

int BulletManager::IsPlayerHit(SDL_Rect *hitbox)
{
    for(int i=0; i<int(enemyBullets.size()); i++)
    {
        if(enemyBullets[i]->IsEnemyHit(hitbox)) {enemyBullets.erase(enemyBullets.begin()+i); i=i-1; return 1;}
    }
    return 0;
}
        /*                 ENEMY BULLET CREATION                */
void BulletManager::AddEnemyBulletXY(int type, double x, double y, double vx, double vy)
{enemyBullets.push_back(std::unique_ptr<Bullet>(new Bullet(type, x, y, vx, vy)));}

void BulletManager::AddEnemyBullet(int type, double x, double y, double v, double angle)
{ enemyBullets.push_back(std::unique_ptr<Bullet>(new BasicBullet(type, x, y, v, angle)));}

void BulletManager::AddEnemyAccelBullet(int type, double x, double y, double v, double angle, double accel, double minmaxV)
{ enemyBullets.push_back(std::unique_ptr<Bullet>(new AcceleratingBullet(type, x, y, v, angle, accel, minmaxV)));}

void BulletManager::AddEnemyAccelBulletXY(int type, double x, double y, double vx, double vy, double accelX, double accelY,
                        double minmaxX, double minmaxY)
{enemyBullets.push_back(std::unique_ptr<Bullet>(new AcceleratingBulletXY(type, x, y, vx, vy, accelX, accelY, minmaxX, minmaxY)));}

void BulletManager::AddEnemyComplexBullet(int type, double x, double y, double v, double angle, double angularV,
                        double accel, double minmaxV)
{enemyBullets.push_back(std::unique_ptr<Bullet>(new ComplexBullet(type, x, y, v, angle, angularV, accel, minmaxV)));}

void BulletManager::AddEnemyBulletData(int time, double v, double angle, double angularV, double accel)
{enemyBullets.back()->AddData(time, v, angle, angularV, accel);}

void BulletManager::SetEnemyBulletTiming(int delay, int lifetime)
{enemyBullets.back()->SetTiming(delay, lifetime);}


         /*                 PLAYER BULLET CREATION                */
void BulletManager::AddPlayerBullet(int type, double x, double y, double vx, double vy, int damage)
{
    playerBullets.push_back(std::unique_ptr<Bullet>(new Bullet(type, x, y, vx, vy)));
    playerBullets.back()->SetDamage(damage);
}

void BulletManager::EraseAllBullets()
{
    enemyBullets.clear();
}
