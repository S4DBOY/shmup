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

        void AddBasicBulletXY(int type, int damage,
                        double x, double y, double vx, double vy);
        void AddBasicBullet(int type, int damage,
                        double x, double y, double v, double angle);
        void AddAccelBullet(int type, int damage,
                        double x, double y, double v, double angle, double accel, double minmaxV);
        void AddAccelBulletXY(int type, int damage,
                        double x, double y, double vx, double vy, double accelX, double accelY, double minmaxX, double minmaxY);
        void AddComplexBullet(int type, int damage,
                        double x, double y, double v, double angle, double angularV, double accel);

        void AddBulletData(int time, int instruction, int setOrChange, double data);

        void SetBulletTiming(int delay, int lifetime);

        void SetOwner(bool owner){currentOwner=owner;};

        void EraseAllBullets();
    protected:
    private:
        bool currentOwner;  //determines whether the last bullet added belonged to the enemy or to the player
        /**
            if currentOwner is 0, returns reference to playerBullets. Otherwise, enemyBullets.
        */
        std::vector<std::unique_ptr<Bullet>> &DetermineOwner();

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
