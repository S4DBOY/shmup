#include "../BASIC/globals.h"
#include "../STATES/states.h"

MainMenu::MainMenu()
{
    frameCounter=0;

}

MainMenu::~MainMenu()
{
}

void MainMenu::Handle_events()
{
    if(event.type==SDL_KEYDOWN)
    {
        SDL_Keycode key=event.key.keysym.sym;
        if(key==SDLK_RETURN) nextState=State::GAME;
        if(key == SDLK_ESCAPE ) nextState = State::EXIT;
    }
    //temporary!
}

void MainMenu::Logic()
{
    if(frameCounter==30) nextState=State::GAME;
}

void MainMenu::Render()
{
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
    SDL_RenderClear(ren);
    SDL_RenderPresent(ren);
}
