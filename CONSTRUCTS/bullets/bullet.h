#ifndef BULLET_H
#define BULLET_H

#include "SDL2/SDL.h"

/**
    \brief A a simple bullet, defined by its
    The base class for other bullet subclasses.
*/
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
        int IsRectHit(SDL_Rect r);
        int IsCircleHit(double x, double y, double r);
        void Draw();

    protected:
        double x, y;
        double vx, vy;
        int time=0, delay=0, lifetime=0;
        double angle;
        SDL_Rect loc, source, hitbox;
        int damage=1;

        int usedSpriteSheet;
        int spriteOrientation;

    private:
};

typedef Bullet BasicBulletXY;

#endif // BULLET_H
