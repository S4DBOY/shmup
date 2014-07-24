#include "bulletManager.h"

#include "basicBullet.h"
#include "acceleratingBullet.h"
#include "acceleratingBulletXY.h"
#include "complexBullet.h"
#include "RESOURCES/images.h"

struct Rect{ double x, y; int w, h; };

BulletManager bulletManager;

BulletManager::BulletManager()
{
	bullets.reserve(10000);
}

void BulletManager::Move()
{
	for (auto& bullet : bullets)
		bullet->Move();
}

void BulletManager::Logic()
{
	for (unsigned int i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i]->CheckBounds()) { bullets.erase(bullets.begin() + i); i = i - 1; }
	}
}

void BulletManager::Draw() const
{
	for (int drawOrder = 0; drawOrder < 3; ++drawOrder)
	{
		for (auto& bullet : bullets)
		{
			if (bullet->drawingOrder == drawOrder) bullet->Draw();
		}
	}
}

int BulletManager::IsEnemyHit(Rect loc)
{
	int change, damage = 0;
	for (unsigned int i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i]->owner == 1) continue;
		change = bullets[i]->IsRectHit(loc);
		damage += change;
		if (change) { bullets.erase(bullets.begin() + i); i = i - 1; }
	}
	return damage;
}

int BulletManager::IsPlayerHit(double x, double y, double radius)
{
	int change, damage = 0;
	for (unsigned int i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i]->owner == 0) continue;
		change = bullets[i]->IsCircleHit(x, y, radius);
		damage += change;
		if (change) { bullets.erase(bullets.begin() + i); i = i - 1; }
	}
	return damage;
}

void BulletManager::AddBasicBulletXY(const std::string & type, int damage,
	double x, double y, double vx, double vy)
{
	bullets.push_back(std::make_unique<BasicBulletXY>(type, x, y, vx, vy));
	bullets.back()->owner = currentOwner;
	bullets.back()->SetDamage(damage);
}

void BulletManager::AddBasicBullet(const std::string & type, int damage,
	double x, double y, double v, double angle)
{
	bullets.push_back(std::make_unique<BasicBullet>(type, x, y, v, angle));
	bullets.back()->owner = currentOwner;
	bullets.back()->SetDamage(damage);
}

void BulletManager::AddAccelBullet(const std::string & type, int damage,
	double x, double y, double v, double angle, double accel, double minmaxV)
{
	bullets.push_back(std::make_unique<AcceleratingBullet>(type, x, y, v, angle, accel, minmaxV));
	bullets.back()->owner = currentOwner;
	bullets.back()->SetDamage(damage);
}

void BulletManager::AddAccelBulletXY(const std::string & type, int damage,
	double x, double y, double vx, double vy, double accelX, double accelY,
	double minmaxX, double minmaxY)
{
	bullets.push_back(std::make_unique<AcceleratingBulletXY>(type, x, y, vx, vy, accelX, accelY, minmaxX, minmaxY));
	bullets.back()->owner = currentOwner;
	bullets.back()->SetDamage(damage);
}

void BulletManager::AddComplexBullet(const std::string & type, int damage,
	double x, double y, double v, double angle, double angularV, double accel)
{
	bullets.push_back(std::make_unique<ComplexBullet>(type, x, y, v, angle, angularV, accel));
	bullets.back()->owner = currentOwner;
	bullets.back()->SetDamage(damage);
}

void BulletManager::AddBulletData(int time, int instruction, int setOrChange, double data)
{
	bullets.back()->AddData(time, instruction, setOrChange, data);
}

void BulletManager::SetBulletTiming(int delay, int lifetime)
{
	bullets.back()->SetTiming(delay, lifetime);
}

void BulletManager::EraseAllBullets()
{
	bullets.resize(0);
}
