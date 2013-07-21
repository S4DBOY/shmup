#ifndef PLAYER_H
#define PLAYER_H

#include "SDL2/SDL.h"

/**
    Will become the base class for choosable characters in the future
*/
class Player
{
    public:
        Player();
        ~Player();

        void Input();
        void Move();
        void Logic();
        void Draw();
        void DrawHitBox();

        void GetLocation(double &nx, double &ny){nx=x; ny=y; return;};
    protected:
    private:
        int type;
        double x, y;
        double vx, vy;
        SDL_Rect loc;
        double hitboxRadius;

        bool shooting=0;
        bool focus=0;
        int shootingCounter=1;      //makes sure that the player fires at least one shot

        bool up, down, left, right;
};

#endif // PLAYER_H
