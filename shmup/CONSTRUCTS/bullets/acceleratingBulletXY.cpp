#include "acceleratingBulletXY.h"

#include <cmath>
#define M_PI		3.14159265358979323846

AcceleratingBulletXY::AcceleratingBulletXY(const std::string & type,
	double x, double y,
	double vx, double vy,
	double accelX, double accelY,
	double minmaxX, double minmaxY) :
	Bullet(type, x, y, vx, vy),
	accelX(accelX), accelY(accelY), minmaxX(minmaxX), minmaxY(minmaxY)
{}

void AcceleratingBulletXY::MovePattern()
{
	if ((vx + accelX < minmaxX && accelX>0) || (vx + accelX > minmaxX && accelX<0)) vx += accelX;
	else if (accelX) vx = minmaxX;
	if ((vy + accelY < minmaxY && accelY>0) || (vy + accelY>minmaxY && accelY < 0)) vy += accelY;
	else if (accelY) vy = minmaxY;
	angle = atan2(vy, vx)*(180 / M_PI);
}
