#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H

#include <vector>
#include <memory>

class Bullet;
struct Rect;
class BulletManager;
extern BulletManager bulletManager;

/**
    \brief List of possible bullet types, which determine their graphic and hitbox
*/
enum BULLET_TYPE{
    B_BULLET1
};

/**
    \brief Holds possible instructions for the pseudo-scripted bullets (ComplexBullet).
*/
enum BULLET_INSTRUCTION{
    BULLET_ANGLE,
    BULLET_VELOCITY,
    BULLET_ANGULAR_VELOCITY,
    BULLET_ACCEL,
};
enum SET_OR_CHANGE{
    SET,
    CHANGE,
};

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
        int IsEnemyHit(Rect loc);
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
        inline std::vector<std::unique_ptr<Bullet>> &DetermineOwner();

        std::vector<std::unique_ptr<Bullet>> enemyBullets;
        std::vector<std::unique_ptr<Bullet>> playerBullets;
};


#endif
