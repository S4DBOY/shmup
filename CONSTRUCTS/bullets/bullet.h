#ifndef BULLET_H
#define BULLET_H

#include "SFML/graphics.hpp"
#include <string>

/**
    \brief A a simple bullet, defined by its
    The base class for other bullet subclasses.
*/

struct Rect;

class Bullet
{
    public:
        Bullet(std::string ntype, double nx, double ny, double nvx, double nvy);
        virtual ~Bullet() {};
        void SetDamage(int n_damage);
        void SetTiming(int n_delay, int n_lifetime);

        virtual void AddData(int, int, int, double){};

        void Move();
        bool CheckBounds();
        int IsRectHit(Rect r);
        int IsCircleHit(double x, double y, double r);
        void Draw();

        int drawingOrder;
    protected:
        virtual void MovePattern(){};

        std::string type;
        double x, y;
        double vx, vy;
        double angle;

        int time=0, delay=0, lifetime=0;
        int animationFrames, animationDelay, currentFrame;

        int hitboxW, hitboxH;
        sf::RectangleShape hitbox;
        int damage=1;

    private:
};

typedef Bullet BasicBulletXY;

#endif // BULLET_H
