#ifndef MANAGERS_H
#define MANAGERS_H

#include <vector>
#include <memory>

struct SDL_Rect;

class Bullet;
class Effect;
class Enemy;
class Player;


/**
    \brief A wrapper for a Bullet type vector
*/
class BulletManager
{
    public:
        BulletManager();
        ~BulletManager();

        void Move();
        void Logic();
        void Draw();
        int IsEnemyHit(SDL_Rect loc);
        int IsPlayerHit(double x, double y, double radius);

        void AddEnemyBulletXY(int type, double x, double y, double vx, double vy);
        void AddEnemyBullet(int type, double x, double y, double v, double angle);
        void AddEnemyAccelBullet(int type, double x, double y, double v, double angle, double accel, double minmaxV);
        void AddEnemyAccelBulletXY(int type, double x, double y, double vx, double vy, double accelX, double accelY,
                                        double minmaxX, double minmaxY);
        void AddEnemyComplexBullet(int type, double x, double y, double v, double angle, double angularV, double accel);

        void AddEnemyBulletData(int time, int instruction, int setOrChange, double data);
        void SetEnemyBulletTiming(int delay, int lifetime);

        void AddPlayerBullet(int type, double x, double y, double vx, double vy, int damage);


        void EraseAllBullets();
    protected:
    private:
        std::vector<std::unique_ptr<Bullet>> enemyBullets;
        std::vector<std::unique_ptr<Bullet>> playerBullets;
};

/**
    \brief List of possible bullet types, which determine their graphic and hitbox
*/
enum BULLET_TYPE{
    B_BULLET1
};

/**
    \brief A wrapper for a Effect type vector
*/
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

/**
    \brief List of possible effect types, which determine their graphics and behaviour
*/
enum EFFECT_TYPE{
    EF_EFFECT1
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

/**
    \brief List of possible enemy types, which determine their graphic and hitbox. May be deleted in the future
*/
enum ENEMY_TYPE{
    E_ENEMY1
};

/**
    \brief A wrapper for the Player type opject
*/
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

extern BulletManager bulletManager;
extern EffectManager effectManager;
extern EnemyManager enemyManager;
extern PlayerManager playerManager;

#endif // MANAGERS_H
