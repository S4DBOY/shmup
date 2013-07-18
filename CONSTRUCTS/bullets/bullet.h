#ifndef BULLET_H
#define BULLET_H

#include "../../BASIC/globals.h"

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
        int IsRectHit(SDL_Rect *r);
        int IsCircleHit(double x, double y, double r);
        void Draw();

    protected:
        int type;
        double x, y;
        double vx, vy;
        int time=0, delay=0, lifetime=0;
        double angle;
        SDL_Rect loc, source, hitbox;
        int damage=1;

        double X1, Y1, X2, Y2, X3, Y3, X4, Y4; //hitbox
        double dx1, dx2, dy1, dy2;
        double P1, P2, P3, P4, P, Px, Py, Pmax, Pmin;
        double A1, A2, A3, A4, Amax, Amin;
    private:
};

#endif // BULLET_H

