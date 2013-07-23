#include "../BASIC/system.h"

#include "../BASIC/globals.h"
#include "../RESOURCES/images.h"
#include "../RESOURCES/sound.h"
#include "../STATES/states.h"

#include <ctime>
#include <sstream>      //to be deleted in release
#include <fstream>      //to be deleted in release
#include <cstdlib>

System *SDLsystem;

std::ofstream debugData ("debugData.txt");

System::System()
{
    InitializeGlobals();
    if(Setup()==1)  stateID = State::EXIT;
    LoadImages();
    LoadSounds();

    old=SDL_GetPerformanceCounter();
}

System::~System()
{
    UnloadImages();
    UnloadSounds();

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(window);

    CloseImageLibrary();
    CloseSoundLibrary();
    SDL_Quit();
        /*          performance data            */
    debugData<<std::endl;
    debugData<<"resolution: "<<SCREEN_WIDTH<<"/"<<SCREEN_HEIGHT<<", "<<FRAMES_PER_SECOND<<" FPS, vsync: "<<VSYNC<<", fullscreen: "<<FULLSCREEN<<std::endl;
    debugData<<std::endl;
    debugData<<sumEmptyLoops/(frameCounter-120)<<" empty loops per frame on average"<<std::endl;
    debugData<<nSlowDowns<<" slowdowns, "<<60*nSlowDowns/(frameCounter-120.0)<<" per sec"<<std::endl;
    debugData<<"program lasted for "<<frameCounter<<" frames"<<std::endl;
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
    std::ostringstream performance;
    performance << 1/dt<<" "<<emptyloop;
    SDL_SetWindowTitle(window, performance.str().c_str());

    if(frameCounter>120) sumEmptyLoops+=emptyloop;
    if(frameCounter>120 && 1/dt<59.9) {debugData<<"frame "<<frameCounter<<" , "<<emptyloop<<" "<<1/dt<<std::endl; nSlowDowns++;}

    emptyloop=0;
    return 0;
}

void System::Handle_events()
{
    if( event.type == SDL_QUIT ) {SetNextState(State::EXIT); return;}
    if( event.type == SDL_KEYDOWN )
    {
        if(event.key.keysym.sym == SDLK_F4 && ( event.key.keysym.mod & KMOD_ALT) )
            {SetNextState(State::EXIT); return;}
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

    InitImageLibrary();

    InitSoundLibrary();

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

    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );

        /* placeholder for loading program icon */
    //SDL_Surface* icon = SDL_LoadBMP("icon.bmp");
    //SDL_SetWindowIcon(window, icon);

    SDL_SetWindowTitle(window, "Shmup");

    SDL_ShowCursor(SDL_DISABLE);

    srand(time(0));

    return 0;
}
