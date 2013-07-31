#include "../BASIC/globals.h"
#include "../STATES/states.h"

#include "../CONSTRUCTS/managers.h"

Game::Game()
{
    playerManager.AddPlayer(0);
    enemyManager.AddEnemy(E_ENEMY1, SCREEN_WIDTH/2, 200, 0, 0);
    backgroundManager.SetBackground();
}

Game::~Game()
{

}

void Game::Handle_events()
{
    playerManager.Input();
    if( event.type == sf::Event::KeyPressed )
    {
        if(event.key.code == sf::Keyboard::Escape ) SetNextState(State::PAUSE);
    }
}

void Game::Logic()
{
    backgroundManager.Logic();
    playerManager.Move();
    enemyManager.Move();
    bulletManager.Move();

    bulletManager.SetOwner(0);
    playerManager.Logic();

    bulletManager.SetOwner(1);
    bulletManager.Logic();
    enemyManager.Logic();
    effectManager.Logic();
}

void Game::Render()
{
    backgroundManager.Draw();
    enemyManager.Draw();
    playerManager.Draw();
    effectManager.Draw();
    bulletManager.Draw();
    playerManager.DrawHitBox();
}
