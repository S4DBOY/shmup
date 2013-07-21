#ifndef IMAGES_H
#define IMAGES_H

#include "SDL2/SDL.h"

extern SDL_Texture *bulletSheet;
extern SDL_Texture *background;
extern SDL_Texture *imgplayer;
extern SDL_Texture *effectsSheet;
//extern SDL_Texture *backgroundOverlay;

void LoadImages();
void UnloadImages();

#endif // IMAGES_H
