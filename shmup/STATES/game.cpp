#include "BASIC/globals.h"
#include "STATES/states.h"

#include "CONSTRUCTS/managers.h"

Game::Game()
{
    backgroundManager.SetBackground();
}

Game::~Game()
{

}

void Game::Handle_events(const sf::Event &event)
{
    playerManager.Input(event);
    if( event.type == sf::Event::KeyPressed )
    {
        if(event.key.code == sf::Keyboard::Escape ) SetNextState(State::PAUSE);
    }
    if(event.type==sf::Event::LostFocus) SetNextState(State::PAUSE);
}

void Game::Logic()
{
    backgroundManager.Logic();
    playerManager.Move();
    enemyManager.Move();
    bulletManager.Move();

    playerManager.Logic();

    bulletManager.Logic();
    enemyManager.Logic();
    effectManager.Logic();

    StageLogic();
    stateFrameCounter++;
}

void Game::Render() const
{
    backgroundManager.Draw();
    enemyManager.Draw();
    playerManager.Draw();
    effectManager.Draw();
    bulletManager.Draw();
    playerManager.DrawHitBox();
}
