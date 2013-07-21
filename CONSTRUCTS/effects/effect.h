#ifndef EFFECT_H
#define EFFECT_H

#include "SDL2/SDL.h"

/**
    The base Effect class. Mostly a placeholder right now.
*/
class Effect
{
    public:
        Effect(int ntype, double nx, double ny, int nlife):
            type(ntype), x(nx), y(ny), life(nlife) {};
        virtual ~Effect() {};

        virtual void Draw()=0;
        bool isDead() {return time>life;}

    protected:
        int type;
        double x, y;
        int time, life;

        SDL_Rect loc, source;
    private:
};

#endif // EFFECT_H

