#include "acceleratingBulletXY.h"

#include <cmath>
#define M_PI		3.14159265358979323846

AcceleratingBulletXY::AcceleratingBulletXY(std::string n_type, double n_x, double n_y,
                        double n_vx, double n_vy,
                        double n_accelX, double n_accelY,
                        double n_minmaxX, double n_minmaxY):
        Bullet(n_type, n_x, n_y, n_vx, n_vy),
        accelX(n_accelX), accelY(n_accelY), minmaxX(n_minmaxX), minmaxY(n_minmaxY)
    {}

void AcceleratingBulletXY::MovePattern()
{
    if((vx+accelX<minmaxX && accelX>0) || (vx+accelX>minmaxX && accelX<0)) vx+=accelX;
    else if(accelX) vx=minmaxX;
    if((vy+accelY<minmaxY && accelY>0) || (vy+accelY>minmaxY && accelY<0)) vy+=accelY;
    else if(accelY) vy=minmaxY;
    angle=atan2(vy, vx)*(180/M_PI);
}
