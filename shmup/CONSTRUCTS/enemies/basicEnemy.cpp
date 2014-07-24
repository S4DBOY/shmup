#include "basicEnemy.h"

#include "BASIC/globals.h"
#include "CONSTRUCTS/managers.h"
#include "CONSTRUCTS\bullets\bullet.h"

class EnemyBullet : public Bullet{
public:
	EnemyBullet(BulletType type, double x, double y, double v, double angle, int direction) :
		Bullet(type, x, y, v, angle),
		direction(direction)
	{}
private:
	int direction;
	void MovePattern(){
		if (time == 45){ angularV = direction * 5; accel = -0.1; }
		if (time == 55){ angularV = 0; accel = 0; }
	}
};

BasicEnemy::BasicEnemy(int ntype, double nx, double ny, double nvx, double nvy) :
Enemy(ntype, nx, ny, nvx, nvy)
{
	maxHealth = 3000;
	health = maxHealth;
}

void BasicEnemy::Logic()
{
	double a = (frame / 10) % 360;
	double basev = 4;
	if (frame % 20 == 1)
	{
		for (int i = 0; i < 360; i += 15)
		{
			bulletManager.AddBullet(std::make_unique<EnemyBullet>(B_BULLET1, x, y, basev, i - a, 1));
			bulletManager.AddBullet(std::make_unique<EnemyBullet>(B_BULLET1, x, y, basev, i + a, -1));
		}
	}
	double angle = GetAngleToPlayer(x, y);
	if (frame % 120 == 0)
		for (int i = -3; i <= 3; i += 1)
			bulletManager.AddBullet(std::make_unique<Bullet>(B_BULLET1, x, y, 5, angle + i));
}
