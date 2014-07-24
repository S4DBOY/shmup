#ifndef ACCELERATINGBULLETXY_H
#define ACCELERATINGBULLETXY_H

#include "bullet.h"

/**
	\brief A bullet able to change its velocity in X and Y axid independently
	*/
class AcceleratingBulletXY : public Bullet
{
public:
	AcceleratingBulletXY(const std::string & type,
		double x, double y,
		double vx, double vy,
		double accelX, double accelY,
		double minmaxX, double minmaxY);
	~AcceleratingBulletXY(){};
protected:
private:
	void MovePattern();
	double accelX, accelY;
	double minmaxX, minmaxY;
};

#endif // ACCELERATINGBULLETXY_H
