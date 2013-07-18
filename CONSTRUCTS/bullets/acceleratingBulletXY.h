#ifndef ACCELERATINGBULLETXY_H
#define ACCELERATINGBULLETXY_H

#include "bullet.h"

class AcceleratingBulletXY : public Bullet
{
    public:
        AcceleratingBulletXY(int n_type, double n_x, double n_y,
                        double n_vx, double n_vy,
                        double n_accelX, double n_accelY,
                        double n_minmaxX, double n_minmaxY);
        ~AcceleratingBulletXY(){};

        void Move();
    protected:
    private:
        double accelX, accelY;
        double minmaxX, minmaxY;
};

#endif // ACCELERATINGBULLETXY_H
