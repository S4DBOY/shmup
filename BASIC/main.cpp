#if defined(WIN32) || defined(_WINDOWS)
#  define WIN32_LEAN_AND_MEAN
#  define NOMINMAX
#  include <windows.h>
#endif

#include "../BASIC/globals.h"
#include "../BASIC/system.h"
#include "../STATES/states.h"

int main(int argc, char *argv[])
{
    SDLsystem = new System();

    SetNextState(State::MAINMENU);
    ChangeState();

    while( stateID != State::EXIT )
    {
        while(SDL_PollEvent(&event))
        {
            SDLsystem->Handle_events();
            currentState->Handle_events();
        }

            /*   FPS limiter   */
        if(VSYNC==0) if( SDLsystem->RegulateFPS()) continue;

        frameCounter++;

        currentState->Logic();
        currentState->Render();
        ChangeState();

        SDL_Delay(1);
    }

    delete SDLsystem;
    return 0;
}
