#include "../RESOURCES/images.h"

#include "../BASIC/globals.h"
#include "SDL2/SDL_image.h"

SDL_Texture *textures[4];

void InitImageLibrary()
{
    IMG_Init(IMG_INIT_PNG);
}
void CloseImageLibrary()
{
    IMG_Quit();
}


SDL_Texture *LoadImage(const char *filename)
{
    SDL_Surface* loadedImage = IMG_Load(filename);  //the function needs C-style strings
    return SDL_CreateTextureFromSurface(ren, loadedImage);
}

void LoadImages()
{
    textures[0]=LoadImage("data/bg.dat");
    textures[1]=LoadImage("data/bullet.dat");
    textures[2]=LoadImage("data/effects.dat");
    textures[3]=LoadImage("data/player.dat");
}

void UnloadImages()
{
    for (unsigned i=0;i<4;++i)
    {
        SDL_DestroyTexture(textures[i]);
        textures[i]=nullptr;
    }
}
