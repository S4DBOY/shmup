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
    SFMLsystem = new System();

    SetNextState(State::MAINMENU);
    ChangeState();

    while( stateID != State::EXIT )
    {
        while(window.pollEvent(event))
        {
            SFMLsystem->Handle_events();
            currentState->Handle_events();
        }

        if( SFMLsystem->RegulateFPS()) continue;

        frameCounter++;

        currentState->Logic();
        currentState->Render();
        window.display();
        ChangeState();

        sf::sleep(sf::milliseconds(5));
    }

    delete SFMLsystem;
    return 0;
}
