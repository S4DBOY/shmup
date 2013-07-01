#ifndef PLAYER_H
#define PLAYER_H

#include "../../BASIC/globals.h"

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
    protected:
    private:
        int type;
        double x, y;
        double vx, vy;
        SDL_Rect loc;

        bool shooting=0;
        bool focus=0;
        bool up, down, left, right;
};

#endif // PLAYER_H
