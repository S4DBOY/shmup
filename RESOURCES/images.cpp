#include "../RESOURCES/images.h"

#include "../BASIC/globals.h"
#include "SDL2/SDL_image.h"

SDL_Texture *bulletSheet=nullptr;
SDL_Texture *background=nullptr;
SDL_Texture *imgplayer=nullptr;
SDL_Texture *effectsSheet=nullptr;
//SDL_Texture *backgroundOverlay=nullptr;

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
    bulletSheet=LoadImage("data/bullet.dat");
    background=LoadImage("data/bg.dat");
    //backgroundOverlay=LoadImage("data/bgOverlay.dat");
    imgplayer=LoadImage("data/player.dat");
    effectsSheet=LoadImage("data/effects.dat");
}

void UnloadImages()
{
    SDL_DestroyTexture(bulletSheet);
    SDL_DestroyTexture(background);
    //SDL_DestroyTexture(backgroundOverlay);
    SDL_DestroyTexture(imgplayer);
    SDL_DestroyTexture(effectsSheet);
}
