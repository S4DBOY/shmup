#include "acceleratingBulletXY.h"

AcceleratingBulletXY::AcceleratingBulletXY(int n_type, double n_x, double n_y,
                        double n_vx, double n_vy,
                        double n_accelX, double n_accelY,
                        double n_minmaxX, double n_minmaxY):
        Bullet(n_type, n_x, n_y, n_vx, n_vy),
        accelX(n_accelX), accelY(n_accelY), minmaxX(n_minmaxX), minmaxY(n_minmaxY)
    {}

AcceleratingBulletXY::~AcceleratingBulletXY()
{
    //dtor
}

void AcceleratingBulletXY::Move()
{
    time++;
    if(time<=delay) return;
    x+=vx;
    y+=vy;
    if((vx+accelX<minmaxX && accelX>0) || (vx+accelX>minmaxX && accelX<0)) vx+=accelX;
    else if(accelX) vx=minmaxX;
    if((vy+accelY<minmaxY && accelY>0) || (vy+accelY>minmaxY && accelY<0)) vy+=accelY;
    else if(accelY) vy=minmaxY;
    angle=atan2(vy, vx)*(180/M_PI)+90;
}
