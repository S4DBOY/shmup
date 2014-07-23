#include "basicBullet.h"
#include <cmath>
#define M_PI		3.14159265358979323846

BasicBullet::BasicBullet(std::string ntype, double nx, double ny, double nv, double nangle):
    Bullet(ntype, nx, ny, nv*cos((nangle)*(M_PI/180)), nv*sin((nangle)*(M_PI/180)))
{
    angle=nangle;
}
