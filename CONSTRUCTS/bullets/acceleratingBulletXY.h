#ifndef ACCELERATINGBULLETXY_H
#define ACCELERATINGBULLETXY_H

#include "bullet.h"

/**
    \brief A bullet able to change its velocity in X and Y axid independently
*/
class AcceleratingBulletXY : public Bullet
{
    public:
        AcceleratingBulletXY(std::string n_type, double n_x, double n_y,
                        double n_vx, double n_vy,
                        double n_accelX, double n_accelY,
                        double n_minmaxX, double n_minmaxY);
        ~AcceleratingBulletXY(){};
    protected:
    private:
        void MovePattern();
        double accelX, accelY;
        double minmaxX, minmaxY;
};

#endif // ACCELERATINGBULLETXY_H
