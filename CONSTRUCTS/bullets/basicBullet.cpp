#include "basicBullet.h"
#include <cmath>

#include "../../RESOURCES/images.h"

BasicBullet::BasicBullet(int ntype, double nx, double ny, double nv, double nangle):
    Bullet(ntype, nx, ny, nv*cos((nangle)*(M_PI/180)), nv*sin((nangle)*(M_PI/180)))
{
    angle=nangle+90;
}

BasicBullet::~BasicBullet()
{
}
