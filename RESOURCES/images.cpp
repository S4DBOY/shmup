#include "../RESOURCES/images.h"

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
    bulletSheet=LoadImage("data/bullet.png");
    background=LoadImage("data/bg.png");
    //backgroundOverlay=LoadImage("data/bgOverlay.png");
    imgplayer=LoadImage("data/player.png");
    effectsSheet=LoadImage("data/effects.png");
}

void UnloadImages()
{
    SDL_DestroyTexture(bulletSheet);
    SDL_DestroyTexture(background);
    //SDL_DestroyTexture(backgroundOverlay);
    SDL_DestroyTexture(imgplayer);
    SDL_DestroyTexture(effectsSheet);
}
