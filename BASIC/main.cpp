#if defined(WIN32) || defined(_WINDOWS)
#  define WIN32_LEAN_AND_MEAN
#  define NOMINMAX
#  include <windows.h>
#endif

#include "../BASIC/system.h"
#include "../STATES/states.h"

int main(int argc, char *argv[])
{
    SDLsystem = new System();

    stateID = State::MAINMENU;
    currentState = new MainMenu();

    while( stateID != State::EXIT )
    {
        currentState->Handle_events();

            /*   FPS limiter   */
        if(VSYNC==0) if( SDLsystem->RegulateFPS()) continue;

        frameCounter++;

        currentState->Logic();
        change_state();
        currentState->Render();

        SDL_Delay(1);
    }

    delete SDLsystem;
    return 0;
}
