#pragma once

#include <memory>

class Player;
class PlayerManager;
extern PlayerManager playerManager;

namespace sf{
	class Event;
}

class PlayerManager
{
public:
	void Input(const sf::Event &event);
	void Move();
	void Logic();
	void Draw() const;
	void DrawHitBox() const;
	void AddPlayer(int type);

	void GetPlayerLocation(double &x, double &y) const;
protected:
private:
	std::unique_ptr<Player> player;
};
