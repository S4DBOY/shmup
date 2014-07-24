#pragma once

namespace sf { class Event; }

class Player
{
public:
	Player();

	void Input(const sf::Event &event);
	void Move();
	void Logic();
	void Draw() const;
	void DrawHitBox() const;

	void GetLocation(double &nx, double &ny) const
	{
		nx = x; ny = y; return;
	};
	void GetHitBox(double &Cx, double &Cy, double &Cr) const
	{
		Cx = x; Cy = y; Cr = hitboxRadius;
	};
	bool IsDying() const
	{
		return health <= 0;
	}
	void ReduceHealth(int damage)
	{
		health -= damage;
	}
	void Die();
protected:
private:
	int type;
	double x, y;
	double vx, vy;
	double hitboxRadius;
	int maxHealth = 1000, health = maxHealth;

	bool shooting = false;
	bool focus = false;
	int shootingCounter = 1;      //makes sure that the player fires at least one shot

	bool up, down, left, right;
};