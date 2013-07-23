#ifndef ENEMY_H
#define ENEMY_H

#include "SDL2/SDL.h"

/**
    The base Enemy class
*/
class Enemy
{
    public:
        Enemy(int ntype, double nx, double ny, double nvx, double nvy):
            type(ntype), x(nx), y(ny), vx(nvx), vy(nvy) {};
        virtual ~Enemy() {};

        void Move(){x+=vx;y+=vy;};
        virtual void Logic()=0;
        bool IsDying(){return health<=0;}
        void ReduceHealth(int damage){health-=damage;}
        SDL_Rect GetLoc(){return loc;}
        virtual void Draw();
    protected:
        int type;
        int health;
        double x, y;
        double vx, vy;
        SDL_Rect loc, source;

        void GetVectorToPlayer(double x, double y, double &vectorX, double &vectorY);
        double GetAngleToPlayer(double x, double y);

    private:

};

#endif // ENEMY_H

