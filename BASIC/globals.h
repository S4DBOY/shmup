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

#endif // GLOBALS_H
