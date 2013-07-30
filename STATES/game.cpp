#include "../BASIC/globals.h"
#include "../STATES/states.h"

#include "../CONSTRUCTS/playerManager.h"
#include "../CONSTRUCTS/effectManager.h"
#include "../CONSTRUCTS/enemyManager.h"
#include "../CONSTRUCTS/bulletManager.h"

#include "../RESOURCES/images.h"

Game::Game()
{
    playerManager.AddPlayer(0);
    frameCounter=0;
    enemyManager.AddEnemy(E_ENEMY1, SCREEN_WIDTH/2, 200, 0, 0);
}

Game::~Game()
{

}

void Game::Handle_events()
{
    playerManager.Input();
    if( event.type == sf::Event::KeyPressed )
    {
        if(event.key.code == sf::Keyboard::Escape ) SetNextState(State::EXIT);
    }
}

void Game::Logic()
{
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
    window.draw(backgroundGraphic);

    enemyManager.Draw();

    playerManager.Draw();

    bulletManager.Draw();
    effectManager.Draw();
    playerManager.DrawHitBox();

    window.display();
}
