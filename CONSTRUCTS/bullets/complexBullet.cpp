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
    if(accel || angularV) CalculateVelocity();

    if(instructions.size()!=0)
    {
        instructionStruct i=instructions.front();
        while(time==i.time)
        {
            int c=i.setOrChange;
            switch (i.instruction)
            {
                case BULLET_VELOCITY:{v=c*v-(c-1)*i.data+c*i.data; CalculateVelocity();} break;
                case BULLET_ANGLE:{angle=c*angle-(c-1)*i.data+c*i.data; CalculateVelocity();} break;
                case BULLET_ACCEL:{accel=c*accel-(c-1)*i.data+c*i.data;} break;
                case BULLET_ANGULAR_VELOCITY:{angularV=c*angularV-(c-1)*i.data+c*i.data;} break;
            }
            instructions.erase(instructions.begin());
            if(instructions.size()!=0) i=instructions.front(); else break;
        }
    }
}

void ComplexBullet::AddData(int time, int instruction, int setOrChange, double data)
{
    instructionStruct i={time, instruction, setOrChange, data};
    instructions.push_back(i);
}

void ComplexBullet::CalculateVelocity()
{
    vx=v*cos((angle-90)*(M_PI/180));
    vy=v*sin((angle-90)*(M_PI/180));
}
