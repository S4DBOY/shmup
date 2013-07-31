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

    while(!done)
    {
        while(window.pollEvent(event))
        {
            SFMLsystem->Handle_events();
            states.top()->Handle_events();
        }

        if( SFMLsystem->RegulateFPS()) continue;

        frameCounter++;

        states.top()->Logic();

        states.top()->Render();
        window.display();

        ChangeState();

        sf::sleep(sf::milliseconds(5));
    }

    while(!states.empty())
    {
        GameState *next = states.top();
        states.pop(); delete next;
    }

    delete SFMLsystem;
    return 0;
}
