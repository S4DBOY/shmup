#include "complexBullet.h"

#include <cmath>

ComplexBullet::ComplexBullet(int n_type, double n_x, double n_y,
                        double n_v, double n_angle, double n_angularV,
                        double n_accel, double n_minmaxV):
        Bullet(n_type, n_x, n_y, n_v*cos((n_angle)*(M_PI/180)), n_v*sin((n_angle)*(M_PI/180))),
        v(n_v), angularV(n_angularV), accel(n_accel)
{
    angle=n_angle+90;
}

ComplexBullet::~ComplexBullet()
{

}

void ComplexBullet::Move()
{
    time++;
    if(time<=delay) return;
    x+=vx;
    y+=vy;

    angle+=angularV;
    v+=accel;
    if(accel || angularV)
    {
        vx=v*cos((angle-90)*(M_PI/180));
        vy=v*sin((angle-90)*(M_PI/180));
    }
    if(instructions.size()!=0)
    {
        instruction i=instructions.front();
        if(time==i.time)
        {
            if(i.v) v=i.v;
            if(i.angle) angle=i.angle;
            if(i.angle || i.v) {vx=v*cos((angle-90)*(M_PI/180)); vy=v*sin((angle-90)*(M_PI/180)); }
            if(i.angularV) angularV=i.angularV;
            if(i.accel) accel=i.accel;
            instructions.erase(instructions.begin());
        }
    }
}

void ComplexBullet::AddData(int time, double v, double angle, double angularV, double accel)
{
    instruction i={time, v, angle, angularV, accel};
    instructions.push_back(i);
}
