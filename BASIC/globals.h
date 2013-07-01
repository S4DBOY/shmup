#ifndef GLOBALS_H
#define GLOBALS_H

#include "SDL2/SDL.h"

#include <cstdlib>

extern bool FULLSCREEN;
extern bool  VSYNC;
extern int  FRAMES_PER_SECOND;
extern int  SCREEN_WIDTH;
extern int  SCREEN_HEIGHT;

extern SDL_Renderer *ren;

extern SDL_Event event;

extern int frameCounter;

int InitializeGlobals();


enum BULLET_TYPE
{
    B_BULLET1
};

enum ENEMY_TYPE
{
    E_ENEMY1
};

enum EFFECT_TYPE
{
    EF_EFFECT1
};

#endif // GLOBALS_H
