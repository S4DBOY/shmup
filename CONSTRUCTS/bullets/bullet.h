#ifndef BULLET_H
#define BULLET_H

#include "SFML/graphics.hpp"

/**
    \brief A a simple bullet, defined by its
    The base class for other bullet subclasses.
*/

struct Rect;

class Bullet
{
    public:
        Bullet(int ntype, double nx, double ny, double nvx, double nvy);
        virtual ~Bullet() {};
        void SetDamage(int n_damage);
        void SetTiming(int n_delay, int n_lifetime);

        virtual void AddData(int, int, int, double){};

        virtual void Move();
        bool CheckBounds();
        int IsRectHit(Rect r);
        int IsCircleHit(double x, double y, double r);
        void Draw();

    protected:
        double x, y;
        double vx, vy;
        int time=0, delay=0, lifetime=0;
        double angle;
        int hitboxW, hitboxH;
        int damage=1;

        sf::RectangleShape hitbox;

        int spriteOrientation;

    private:
};

typedef Bullet BasicBulletXY;

#endif // BULLET_H
