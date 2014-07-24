#include "acceleratingBullet.h"

#include <cmath>
#define M_PI		3.14159265358979323846

AcceleratingBullet::AcceleratingBullet(const std::string & type, double x, double y,
	double v, double angle,
	double accel, double minmaxV) :
	Bullet(type, x, y, v*cos((angle)*(M_PI / 180)), v*sin((angle)*(M_PI / 180))),
	v(v), accel(accel), minmaxV(minmaxV)
{}

void AcceleratingBullet::MovePattern()
{
	if ((v + accel < minmaxV && accel>0) || (v + accel > minmaxV && accel < 0))
	{
		v += accel;
		CalculateVelocity();
	}
	else if (accel)
	{
		v = minmaxV;
		CalculateVelocity();
	}
}

void AcceleratingBullet::CalculateVelocity()
{
	vx = v*cos((angle)*(M_PI / 180));
	vy = v*sin((angle)*(M_PI / 180));
}
