#include "bulletManager.h"

#include "bullet.h"
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
		if (bullets[i]->friendly == false) continue;
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
		if (bullets[i]->friendly) continue;
		change = bullets[i]->IsCircleHit(x, y, radius);
		damage += change;
		if (change) { bullets.erase(bullets.begin() + i); i = i - 1; }
	}
	return damage;
}

void BulletManager::AddBullet(std::unique_ptr<BulletBase> bullet, bool friendly, int damage)
{
	bullets.push_back(std::move(bullet));
	bullets.back()->friendly = friendly;
	bullets.back()->SetDamage(damage);
}

void BulletManager::SetBulletTiming(int delay, int lifetime)
{
	bullets.back()->SetTiming(delay, lifetime);
}

void BulletManager::EraseAllBullets()
{
	bullets.resize(0);
}
