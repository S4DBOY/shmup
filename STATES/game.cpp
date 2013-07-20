#include "../STATES/states.h"

#include "../CONSTRUCTS/managers.h"

#include "../RESOURCES/images.h"

Game::Game()
{
    playerManager->AddPlayer(0);
    frameCounter=0;
    enemyManager->AddEnemy(E_ENEMY1, SCREEN_WIDTH/2, 200, 0, 0);
}

Game::~Game()
{

}

void Game::Handle_events()
{
    playerManager->Input();
    if( event.type == SDL_KEYDOWN )
    {
        SDL_Keycode key=event.key.keysym.sym;
        if(key == SDLK_ESCAPE )
            {nextState = State::EXIT;}
    }
}

void Game::Logic()
{
    playerManager->Move();
    enemyManager->Move();
    bulletManager->Move();

    playerManager->Logic();
    bulletManager->Logic();
    enemyManager->Logic();
    effectManager->Logic();
}

void Game::Render()
{
    SDL_RenderCopy(ren, background, NULL, NULL);
    SDL_SetRenderDrawColor(ren, 255, 255, 255, 0);

    enemyManager->Draw();

    playerManager->Draw();

    bulletManager->Draw();
    effectManager->Draw();
    playerManager->DrawHitBox();

    SDL_RenderPresent(ren);
}
