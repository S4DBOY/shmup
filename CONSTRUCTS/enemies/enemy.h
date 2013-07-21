#ifndef ENEMY_H
#define ENEMY_H

#include "SDL2/SDL.h"

class Enemy
{
    public:
        Enemy(int ntype, double nx, double ny, double nvx, double nvy):
            type(ntype), x(nx), y(ny), vx(nvx), vy(nvy) {};
        virtual ~Enemy() {};

        void Move(){x+=vx;y+=vy;};
        virtual void Logic()=0;
        bool IsDead(){return health<0;}
        void ReduceHealth(int damage){health-=damage;}
        SDL_Rect GetLoc(){return loc;}
        virtual void Draw();
    protected:
        int type;
        int health;
        double x, y;
        double vx, vy;
        SDL_Rect loc, source;

        void GetVectorToPlayer(double &x, double &y);
        double GetAngleToPlayer();

    private:

};

#endif // ENEMY_H

