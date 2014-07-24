#pragma once

#include "SFML/graphics.hpp"
#include <string>

/**
	\brief A a simple bullet, defined by its
	The base class for other bullet subclasses.
	*/

struct Rect;

class Bullet
{
public:
	Bullet(const std::string &type, double x, double y, double vx, double vy);
	virtual ~Bullet() {};
	void SetDamage(int n_damage);
	void SetTiming(int n_delay, int n_lifetime);

	virtual void AddData(int, int, int, double){};

	void Move();
	bool CheckBounds() const;
	int IsRectHit(Rect r) const;
	int IsCircleHit(double x, double y, double r) const;
	void Draw() const;

	int drawingOrder;
	int owner;
protected:
	virtual void MovePattern(){};

	std::string type;
	double x, y;
	double vx, vy;
	double angle;

	int time = 0, delay = 0, lifetime = 0;
	int animationFrames, animationDelay, currentFrame;

	int hitboxW, hitboxH;
	sf::RectangleShape hitbox;
	int damage = 1;

private:
};

typedef Bullet BasicBulletXY;