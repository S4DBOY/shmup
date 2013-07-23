#include "managers.h"

#include "../CONSTRUCTS/player/player.h"

PlayerManager playerManager;

PlayerManager::~PlayerManager()
{if(player) delete player; player=nullptr;}

void PlayerManager::Input()
{player->Input();}

void PlayerManager::Move()
{player->Move();}

void PlayerManager::Logic()
{player->Logic();}

void PlayerManager::Draw()
{player->Draw();}

void PlayerManager::DrawHitBox()
{player->DrawHitBox();}

void PlayerManager::AddPlayer(int type)
{player=new Player();}


void PlayerManager::GetPlayerLocation(double &x, double &y)
{
    player->GetLocation(x, y);
}
