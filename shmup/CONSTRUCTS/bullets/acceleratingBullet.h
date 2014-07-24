#pragma once

#include "bullet.h"

class AcceleratingBullet : public Bullet
{
public:
	AcceleratingBullet(const std::string &type, double x, double y,
		double v, double angle,
		double accel, double minmaxV);
	~AcceleratingBullet(){};

protected:
private:
	void MovePattern();
	double v;
	double accel;
	double minmaxV;

	void CalculateVelocity();
};