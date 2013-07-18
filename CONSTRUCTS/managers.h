#ifndef MANAGERS_H
#define MANAGERS_H

#include "../BASIC/globals.h"

#include <vector>
#include <memory>


class Bullet;
class Effect;
class Enemy;
class Player;

class BulletManager
{
    public:
        BulletManager();
        ~BulletManager();

        void Move();
        void Logic();
        void Draw();
        int IsEnemyHit(SDL_Rect *loc);
        int IsPlayerHit(double x, double y, double radius);

        void AddEnemyBulletXY(int type, double x, double y, double vx, double vy);
        void AddEnemyBullet(int type, double x, double y, double v, double angle);
        void AddEnemyAccelBullet(int type, double x, double y, double v, double angle, double accel, double minmaxV);
        void AddEnemyAccelBulletXY(int type, double x, double y, double vx, double vy, double accelX, double accelY,
                                        double minmaxX, double minmaxY);
        void AddEnemyComplexBullet(int type, double x, double y, double v, double angle, double angularV,
                                    double accel, double minmaxV);

        void AddEnemyBulletData(int time, int instruction, int setOrChange, double data);
        void SetEnemyBulletTiming(int delay, int lifetime);

        void AddPlayerBullet(int type, double x, double y, double vx, double vy, int damage);


        void EraseAllBullets();
    protected:
    private:
        std::vector<std::unique_ptr<Bullet>> enemyBullets;
        std::vector<std::unique_ptr<Bullet>> playerBullets;
};

enum BULLET_TYPE
{
    B_BULLET1
};


class EffectManager
{
    public:
        EffectManager();
        ~EffectManager();

        void Logic();
        void Draw();
        void AddEffect(int type, double x, double y);
    protected:
    private:
        std::vector<std::unique_ptr<Effect>> effects;
};

enum EFFECT_TYPE
{
    EF_EFFECT1
};

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

enum ENEMY_TYPE
{
    E_ENEMY1
};

class PlayerManager
{
    public:
        PlayerManager(){};
        ~PlayerManager();
        void Input();
        void Move();
        void Logic();
        void Draw();
        void DrawHitBox();
        void AddPlayer(int type);

        void GetPlayerLocation(double &x, double &y);
    protected:
    private:
        Player *player;
};

extern BulletManager *bulletManager;
extern EffectManager *effectManager;
extern EnemyManager *enemyManager;
extern PlayerManager *playerManager;

#endif // MANAGERS_H
