#ifndef IMAGES_H
#define IMAGES_H

#include "SDL2/SDL.h"

extern SDL_Texture *bulletSheet;
extern SDL_Texture *background;
extern SDL_Texture *imgplayer;
extern SDL_Texture *effectsSheet;
//extern SDL_Texture *backgroundOverlay;


void InitImageLibrary();
void CloseImageLibrary();

/**
\brief Loads all images and converts them to textures.
*/
void LoadImages();

/**
\brief Frees all textures.
*/
void UnloadImages();

#endif // IMAGES_H
