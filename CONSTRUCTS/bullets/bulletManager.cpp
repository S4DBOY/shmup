#include "bulletManager.h"

#include "basicBullet.h"
#include "acceleratingBullet.h"
#include "acceleratingBulletXY.h"
#include "complexBullet.h"
#include "../../RESOURCES/images.h"

struct Rect{double x, y; int w, h;};

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
    for(unsigned int i=0; i<playerBullets.size(); ++i) playerBullets[i]->Draw();

    for(int drawOrder=0; drawOrder<3; ++drawOrder)
    {
        for(unsigned int i=0; i<enemyBullets.size(); ++i)
        {
            if(enemyBullets[i]->drawingOrder==drawOrder) enemyBullets[i]->Draw();
        }
    }
}

int BulletManager::IsEnemyHit(Rect loc)
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

void BulletManager::AddBasicBulletXY(std::string type, int damage,
                                    double x, double y, double vx, double vy)
{
    DetermineOwner().push_back(std::unique_ptr<Bullet>(new BasicBulletXY(type, x, y, vx, vy)));
    DetermineOwner().back()->SetDamage(damage);
}

void BulletManager::AddBasicBullet(std::string type, int damage,
                                    double x, double y, double v, double angle)
{
    DetermineOwner().push_back(std::unique_ptr<Bullet>(new BasicBullet(type, x, y, v, angle)));
    DetermineOwner().back()->SetDamage(damage);
}

void BulletManager::AddAccelBullet(std::string type, int damage,
                                    double x, double y, double v, double angle, double accel, double minmaxV)
{
    DetermineOwner().push_back(std::unique_ptr<Bullet>(new AcceleratingBullet(type, x, y, v, angle, accel, minmaxV)));
    DetermineOwner().back()->SetDamage(damage);
}

void BulletManager::AddAccelBulletXY(std::string type, int damage,
                                    double x, double y, double vx, double vy, double accelX, double accelY,
                                    double minmaxX, double minmaxY)
{
    DetermineOwner().push_back(std::unique_ptr<Bullet>(new AcceleratingBulletXY(type, x, y, vx, vy, accelX, accelY, minmaxX, minmaxY)));
    DetermineOwner().back()->SetDamage(damage);
}

void BulletManager::AddComplexBullet(std::string type, int damage,
                                    double x, double y, double v, double angle, double angularV, double accel)
{
    DetermineOwner().push_back(std::unique_ptr<Bullet>(new ComplexBullet(type, x, y, v, angle, angularV, accel)));
    DetermineOwner().back()->SetDamage(damage);
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
    enemyBullets.resize(0);
    playerBullets.resize(0);
}
