#pragma once

#include "bullet.h"

class BasicBullet : public Bullet
{
public:
	BasicBullet(const std::string & ntype, double nx, double ny, double nv, double nangle);
	~BasicBullet(){};
protected:
private:
};