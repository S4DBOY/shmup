#ifndef COMPLEXBULLET_H
#define COMPLEXBULLET_H

#include "bullet.h"
#include <vector>


struct instruction
{
    int time;
    double v;
    double angle;
    double angularV;
    double accel;
};

class ComplexBullet : public Bullet
{
    public:
        ComplexBullet(int n_type, double n_x, double n_y,
                        double n_v, double n_angle, double n_angularV,
                        double n_accel, double n_minmaxV);
        ~ComplexBullet();

        void Move();
        void AddData(int time, double v, double angle, double angularV, double accel);
    protected:
    private:
        double v;
        double angularV;
        double accel;
        std::vector<instruction> instructions;
};

#endif // COMPLEXBULLET_H
