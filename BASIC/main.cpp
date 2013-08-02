#if defined(WIN32) || defined(_WINDOWS)
#  define WIN32_LEAN_AND_MEAN
#  define NOMINMAX
#  include <windows.h>
#endif

#include "../BASIC/globals.h"
#include "../BASIC/system.h"
#include "../STATES/states.h"
#include "../RESOURCES/sound.h"
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

        states.top()->Logic();

        states.top()->Render();
        window.display();

        CleanSounds();  //I wish there was a better place for it

        ChangeState();

        frameCounter++;

        sf::sleep(sf::milliseconds(5));
    }

    delete SFMLsystem;
    return 0;
}
