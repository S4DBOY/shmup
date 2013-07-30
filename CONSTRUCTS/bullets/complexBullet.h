#ifndef COMPLEXBULLET_H
#define COMPLEXBULLET_H

#include "bullet.h"
#include <vector>

/**
    \brief a struct for keeping instructions for the bullet to follow
*/
struct InstructionStruct
{
    /// Interval since the bullet's creation (in frames) after which the instruction will be executed
    int time;
    /// The bullet's value to change
    int instruction;
    /// Determines whether the value will be set to a value or changed by the value
    int setOrChange;
    /// New value
    double data;
};

/**
    \brief A bullet with a complex set of instructions
*/
class ComplexBullet : public Bullet
{
    public:
        ComplexBullet(std::string n_type, double n_x, double n_y,
                        double n_v, double n_angle, double n_angularV,
                        double n_accel);
        ~ComplexBullet(){};

        void Move();
        void AddData(int time, int instruction, int setOrChange, double data);
    protected:
    private:
        double v;
        double angularV;
        double accel;
        std::vector<InstructionStruct> instructions;

        void CalculateVelocity();
};

#endif // COMPLEXBULLET_H
