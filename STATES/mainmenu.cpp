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
    if(event.type==sf::Event::KeyPressed)
    {
        if(event.key.code==sf::Keyboard::Return) SetNextState(State::GAME);
        if(event.key.code == sf::Keyboard::Escape ) SetNextState(State::EXIT);
    }
    //temporary!
}

void MainMenu::Logic()
{
    if(frameCounter==30) SetNextState(State::GAME);
}

void MainMenu::Render()
{

}
