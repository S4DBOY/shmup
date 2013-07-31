#ifndef ACCELERATINGBULLET_H
#define ACCELERATINGBULLET_H

#include "bullet.h"

/**
    \brief A bullet able to change its velocity while keeping constant direction.
*/
class AcceleratingBullet : public Bullet
{
    public:
        AcceleratingBullet(std::string n_type, double n_x, double n_y,
                        double n_v, double n_angle,
                        double n_accel, double n_minmaxV);
        ~AcceleratingBullet(){};

    protected:
    private:
        void MovePattern();
        double v;
        double accel;
        double minmaxV;

        void CalculateVelocity();
};

#endif // ACCELERATINGBULLET_H
