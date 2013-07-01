#include "../STATES/states.h"
#include "../BASIC/system.h"

#include "../RESOURCES/images.h"

MainMenu::MainMenu()
{
    frameCounter=0;

}

MainMenu::~MainMenu()
{
}

void MainMenu::Handle_events()
{
    while(SDL_PollEvent(&event))
    {
        SDLsystem->Input();
        if(event.type==SDL_KEYDOWN)
        {
            SDL_Keycode key=event.key.keysym.sym;
            if(key==SDLK_RETURN) nextState=State::GAME;
            if(key == SDLK_ESCAPE ) nextState = State::EXIT;
        }

    }
    if(frameCounter==30) nextState=State::GAME;
}

void MainMenu::Logic()
{
}

void MainMenu::Render()
{
    SDL_RenderCopy(ren, background, NULL, NULL);
    SDL_RenderPresent(ren);
}
