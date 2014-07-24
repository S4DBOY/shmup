#include "playerManager.h"
#include "CONSTRUCTS/bullets/bulletManager.h"

#include "player.h"

PlayerManager playerManager;

void PlayerManager::Input(const sf::Event &event)
{
	player->Input(event);
}

void PlayerManager::Move()
{
	player->Move();
}

void PlayerManager::Logic()
{
	double x, y, r;
	player->GetHitBox(x, y, r);
	player->ReduceHealth(bulletManager.IsPlayerHit(x, y, r));
	if (player->IsDying())
	{
		bulletManager.EraseAllBullets();
		player->Die();
	}

	player->Logic();
}

void PlayerManager::Draw() const
{
	player->Draw();
}

void PlayerManager::DrawHitBox() const
{
	player->DrawHitBox();
}

void PlayerManager::AddPlayer(int type)
{
	player.reset(new Player());
}

void PlayerManager::GetPlayerLocation(double &x, double &y) const
{
	player->GetLocation(x, y);
}
