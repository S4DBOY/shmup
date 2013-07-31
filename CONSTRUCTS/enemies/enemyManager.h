#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include <vector>
#include <memory>

class Enemy;
class EnemyManager;
extern EnemyManager enemyManager;

/**
    \brief List of possible enemy types, which determine their graphic and hitbox. May be deleted in the future
*/
enum ENEMY_TYPE{
    E_ENEMY1
};

/**
    \brief A wrapper for a Enemy type vector
*/
class EnemyManager
{
    public:
        EnemyManager();
        ~EnemyManager();

        void Move();
        void Logic();
        void Draw();
        void AddEnemy(int type, double x, double y, double vx, double vy);
        void KillAllEnemies();
    protected:
    private:
        std::vector<std::unique_ptr<Enemy>> enemies;
};

#endif
