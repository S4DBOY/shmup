#ifndef IMAGES_H
#define IMAGES_H

#include "SDL2/SDL.h"

extern SDL_Texture *textures[4];


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

enum SPRITESHEETS
{
    BACKGROUND1,
    BULLETSHEET1,
    EFFECTSHEET1,
    PLAYERSHEET1
};

#endif // IMAGES_H
