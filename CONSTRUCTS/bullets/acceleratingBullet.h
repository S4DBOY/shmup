#ifndef ACCELERATINGBULLET_H
#define ACCELERATINGBULLET_H

#include "bullet.h"

class AcceleratingBullet : public Bullet
{
    public:
        AcceleratingBullet(int n_type, double n_x, double n_y,
                        double n_v, double n_angle,
                        double n_accel, double n_minmaxV);
        ~AcceleratingBullet(){};

        void Move();
    protected:
    private:
        double v;
        double accel;
        double minmaxV;

        void CalculateVelocity();
};

#endif // ACCELERATINGBULLET_H
