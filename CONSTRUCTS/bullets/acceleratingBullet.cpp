#include "acceleratingBullet.h"

#include <cmath>
#define M_PI		3.14159265358979323846

AcceleratingBullet::AcceleratingBullet(std::string n_type, double n_x, double n_y,
                        double n_v, double n_angle,
                        double n_accel, double n_minmaxV):
        Bullet(n_type, n_x, n_y, n_v*cos((n_angle)*(M_PI/180)), n_v*sin((n_angle)*(M_PI/180))),
        v(n_v), accel(n_accel), minmaxV(n_minmaxV)
    {}

void AcceleratingBullet::MovePattern()
{
    if((v+accel<minmaxV && accel>0) || (v+accel>minmaxV && accel<0))
    {
        v+=accel;
        CalculateVelocity();
    }
    else if(accel)
    {
        v=minmaxV;
        CalculateVelocity();
    }
}

void AcceleratingBullet::CalculateVelocity()
{
    vx=v*cos((angle)*(M_PI/180));
    vy=v*sin((angle)*(M_PI/180));
}
