#pragma once

#include <vector>
#include <memory>

class Enemy;
class EnemyManager;
extern EnemyManager enemyManager;

enum ENEMY_TYPE{
	E_ENEMY1
};

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();

	void Move();
	void Logic();
	void Draw() const;
	void AddEnemy(int type, double x, double y, double vx, double vy);
	void KillAllEnemies();
protected:
private:
	std::vector<std::unique_ptr<Enemy>> enemies;
};
