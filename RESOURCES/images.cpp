#include "../RESOURCES/images.h"

#include "../BASIC/globals.h"
#include "SDL2/SDL_image.h"
#include <string>


SDL_Texture *bulletSheet=nullptr;
SDL_Texture *background=nullptr;
SDL_Texture *imgplayer=nullptr;
SDL_Texture *effectsSheet=nullptr;
//SDL_Texture *backgroundOverlay=nullptr;


SDL_Texture *LoadImage( std::string filename)
{
    SDL_Surface* loadedImage = IMG_Load(filename.c_str());
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
