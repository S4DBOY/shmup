#ifndef BULLET_H
#define BULLET_H

#include "../../BASIC/globals.h"

#include <cmath>

class Bullet
{
    public:
        Bullet(int ntype, double nx, double ny, double nvx, double nvy);
        virtual ~Bullet() {};
        void SetDamage(int n_damage);
        void SetTiming(int n_delay, int n_lifetime);

        virtual void AddData(int, double, double, double, double){};

        virtual void Move();
        virtual bool CheckBounds();
        virtual int IsEnemyHit(SDL_Rect *r);
        virtual void Draw();

    protected:
        int type;
        double x, y;
        double vx, vy;
        int time=0, delay=0, lifetime=0;
        double angle;
        SDL_Rect loc, source;
        int damage=1;
    private:
};

#endif // BULLET_H

