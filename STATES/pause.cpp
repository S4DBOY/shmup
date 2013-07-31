#include "../BASIC/globals.h"
#include "states.h"

#include "../CONSTRUCTS/managers.h"
#include "../RESOURCES/images.h"

Pause::Pause()
{

}

Pause::~Pause()
{

}

void Pause::Handle_events()
{
    playerManager.Input();
    if( event.type == sf::Event::KeyPressed )
    {
        if(event.key.code == sf::Keyboard::Escape ) SetNextState(State::EXIT);
        if(event.key.code == sf::Keyboard::Return )
        {
            delete states.top();
            states.pop();
        }
    }
}

void Pause::Logic()
{
    stateFrameCounter++;
}

void Pause::Render()
{
    backgroundManager.Draw();
    enemyManager.Draw();
    playerManager.Draw();
    effectManager.Draw();
    bulletManager.Draw();
    playerManager.DrawHitBox();
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f{SCREEN_WIDTH, SCREEN_HEIGHT});
    shape.setFillColor(sf::Color{0, 0, 0, sf::Uint8(stateFrameCounter<16? stateFrameCounter*8 : 128)});
    DrawRect(shape);
}
