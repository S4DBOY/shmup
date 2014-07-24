#pragma once
#include "SFML/graphics.hpp"

struct Rect{ double x, y; int w, h; };

/**
	The base Enemy class
	*/
class Enemy
{
public:
	Enemy(int ntype, double nx, double ny, double nvx, double nvy);
	virtual ~Enemy() {};

	void Move(){ x += vx; y += vy; frame++; };
	virtual void Logic() = 0;
	bool IsDying(){ return health <= 0; }
	void ReduceHealth(int damage){ health -= damage; }
	Rect GetLoc(){ return Rect{ x, y, 50, 50 }; }
	virtual void Draw();
protected:
	int type;
	int maxHealth, health;
	int frame = 0;
	double x, y;
	double vx, vy;

	sf::RectangleShape graphic, lifebar, life;

	void GetVectorToPlayer(double x, double y, double &vectorX, double &vectorY);
	double GetAngleToPlayer(double x, double y);

private:

};

