#pragma once

#include <vector>
#include <memory>
#include <string>

struct Rect;
class BulletBase;
class BulletManager;
extern BulletManager bulletManager;

class BulletManager
{
public:
	BulletManager();

	void Move();
	void Logic();
	void Draw() const;
	int IsEnemyHit(Rect loc);
	int IsPlayerHit(double x, double y, double radius);

	void AddBullet(std::unique_ptr<BulletBase> bullet, bool friendly = false, int damage = 1);

	void SetBulletTiming(int delay, int lifetime);

	void EraseAllBullets();
protected:
private:
	std::vector<std::unique_ptr<BulletBase>> bullets;
};