#pragma once

#include "SFML/graphics.hpp"
#include <memory>

struct Rect;

enum BulletType{
	B_BULLET1,
	B_BULLET1_P
};

class BulletBase
{
public:
	BulletBase(BulletType type, double x, double y);
	virtual ~BulletBase() {};
	void SetDamage(int n_damage){ damage = n_damage; };
	void SetTiming(int n_delay, int n_lifetime);

	virtual void Move();
	bool CheckBounds() const;
	int IsRectHit(Rect r) const;
	int IsCircleHit(double x, double y, double r) const;
	void Draw() const;

	int drawingOrder;
	bool friendly;
protected:
	virtual void MovePattern(){};

	BulletType type;
	double x, y;
	double angle;

	int time = 0, delay = 0, lifetime = 0;
	int animationFrames, animationDelay, currentFrame;

	int hitboxW, hitboxH;
	sf::RectangleShape hitbox;
	int damage = 1;

private:
};

class BulletXY : public BulletBase{
public:
	BulletXY(BulletType type, double x, double y, double vx = 0.0, double vy = 0.0);
	virtual ~BulletXY() {};
	void Move();
protected:
	double vx, vy;
	double accelX = 0.0, accelY = 0.0;
};

class Bullet : public BulletBase{
public:
	Bullet(BulletType type, double x, double y, double v = 0.0, double angle = 0.0);
	virtual ~Bullet() {};
	void Move();
protected:
	double v, accel = 0.0;
	double angularV = 0.0;
};