#include "../STATES/states.h"
#include "../BASIC/system.h"

#include "../CONSTRUCTS/managers.h"
#include "../CONSTRUCTS/player/player.h"

#include "../RESOURCES/images.h"

Game::Game()
{
    player=new Player();
    frameCounter=0;
    enemyManager->AddEnemy(E_ENEMY1, SCREEN_WIDTH/2, 200, 0, 0);
}

Game::~Game()
{

}

void Game::Handle_events()
{
    while(SDL_PollEvent(&event))
    {
        SDLsystem->Input();
        player->Input();
        if( event.type == SDL_KEYDOWN )
        {
            SDL_Keycode key=event.key.keysym.sym;
            if(key == SDLK_ESCAPE )
                {nextState = State::EXIT;}
        }
    }
}

void Game::Logic()
{
    player->Move();
    player->Logic();

    enemyManager->Move();
    bulletManager->Move();

    bulletManager->Logic();
    enemyManager->Logic();
    effectManager->Logic();
}

void Game::Render()
{
    SDL_RenderCopy(ren, background, NULL, NULL);
    SDL_SetRenderDrawColor(ren, 255, 255, 255, 0);

    enemyManager->Draw();

    player->Draw();

    bulletManager->Draw();
    effectManager->Draw();
    player->DrawHitBox();

    SDL_RenderPresent(ren);
}
