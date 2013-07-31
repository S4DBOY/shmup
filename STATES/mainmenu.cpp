#include "../BASIC/globals.h"
#include "../STATES/states.h"

#include "../CONSTRUCTS/managers.h"

MainMenu::MainMenu()
{

}

MainMenu::~MainMenu()
{
}

void MainMenu::Handle_events()
{
    if(event.type==sf::Event::KeyPressed)
    {
        if(event.key.code==sf::Keyboard::Return) SetNextState(State::GAME);
        if(event.key.code == sf::Keyboard::Escape ) SetNextState(State::EXIT);
    }
    //temporary!
}

void MainMenu::Logic()
{
    stateFrameCounter++;
    if(stateFrameCounter==30) SetNextState(State::GAME);
}

void MainMenu::Render()
{

}
