#include "../BASIC/system.h"

#include "../RESOURCES/images.h"
#include "../RESOURCES/sound.h"
#include "../CONSTRUCTS/managers.h"
#include "../STATES/states.h"

#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_image.h"

#include <ctime>
#include <cstdio>
#include <sstream>
#include <fstream>

System *SDLsystem;

std::ofstream debugData ("debugData.txt");

System::System()
{
    InitializeGlobals();
    if(Setup()==1)  stateID = State::EXIT;
    LoadImages();
    LoadSounds();
    enemyManager=new EnemyManager();
    bulletManager=new BulletManager();
    effectManager=new EffectManager();


    old=SDL_GetPerformanceCounter();
}

System::~System()
{
    UnloadImages();
    UnloadSounds();
    delete enemyManager;
    delete bulletManager;
    delete effectManager;

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    SDL_Quit();

    debugData<<sumEmptyLoops/(frameCounter-120)<<" empty loops per frame on average"<<std::endl;
    debugData<<nSlowDowns<<" slowdowns, "<<60*nSlowDowns/(frameCounter-120.0)<<" per sec"<<std::endl;
    debugData.close();
}

bool System::RegulateFPS()
{
    now = SDL_GetPerformanceCounter();
    dt = (now - old) / (float)SDL_GetPerformanceFrequency();
    if(dt<=1.0/(FRAMES_PER_SECOND)) {emptyloop++; return 1;}
    if (dt > 0.1) dt = 0.0016;
    old = now;

        /*     FPS counter     */
    std::stringstream performance;
    performance << 1/dt<<" "<<emptyloop;
    SDL_SetWindowTitle(window, performance.str().c_str());

    if(frameCounter>120) sumEmptyLoops+=emptyloop;
    if(frameCounter>120 && 1/dt<59.9) {debugData<<emptyloop<<" "<<1/dt<<std::endl; nSlowDowns++;}


    emptyloop=0;
    return 0;
}

void System::Input()
{
    if( event.type == SDL_QUIT ) {stateID = State::EXIT; return;}
    if( event.type == SDL_KEYDOWN )
    {
        if(event.key.keysym.sym == SDLK_F4 && ( event.key.keysym.mod & KMOD_ALT) )
            {nextState = State::EXIT; return;}
    }
    /*if(event.type==SDL_WINDOWEVENT)
    {
        if(event.window.event==SDL_WINDOWEVENT_FOCUS_LOST  || event.window.event==SDL_WINDOWEVENT_MINIMIZED);

        if(event.window.event==SDL_WINDOWEVENT_FOCUS_GAINED || event.window.event==SDL_WINDOWEVENT_RESTORED);
    }*/

}

void System::ToggleFullscreen()
{
    UnloadImages();
    SDL_DestroyRenderer(ren);

    FULLSCREEN=!FULLSCREEN;
    if(FULLSCREEN)  SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    else            {SDL_SetWindowFullscreen(window, 0); }//SDL_SetWindowSize(window, SCREEN_WIDTH, SCREEN_HEIGHT); }

    ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    LoadImages();
}

bool System::Setup()
{
    if (SDL_Init( SDL_INIT_EVERYTHING ) < 0)
        {printf("SDL_Init: %s\n", SDL_GetError()); return 1;}

    IMG_Init(IMG_INIT_PNG);

    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 512 );

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

    if(FULLSCREEN)
        window = SDL_CreateWindow("SDL2", 5, 30, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
    else window = SDL_CreateWindow("SDL2", 5, 30, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == 0){printf("SDL_CreateWINDOW: %s\n", SDL_GetError()); return 1;}

    if(VSYNC) {ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);
                FRAMES_PER_SECOND=60;}
    else ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (ren == 0){printf("SDL_CreateRenderer: %s\n", SDL_GetError()); return 1;}

        /* placeholder for loading program icon */
    //SDL_Surface* icon = SDL_LoadBMP("icon.bmp");
    //SDL_SetWindowIcon(window, icon);

    SDL_SetWindowTitle(window, "Pong");

    SDL_ShowCursor(SDL_DISABLE);

    int mouse_x, mouse_y;
    SDL_GetMouseState(&mouse_x, &mouse_y);
    srand(time(0)+mouse_x+mouse_y);

    return 0;
}
