#include "complexBullet.h"

#include <cmath>
#define M_PI		3.14159265358979323846

/**
	\brief Holds possible instructions for the pseudo-scripted bullets (ComplexBullet).
	*/
enum BULLET_INSTRUCTION{
	BULLET_ANGLE,
	BULLET_VELOCITY,
	BULLET_ANGULAR_VELOCITY,
	BULLET_ACCEL,
};
enum SET_OR_CHANGE{
	SET,
	CHANGE,
};

ComplexBullet::ComplexBullet(const std::string &type,
	double x, double y,
	double v,
	double angle, double angularV,
	double accel) :
	Bullet(type, x, y, v*cos((angle)*(M_PI / 180)), v*sin((angle)*(M_PI / 180))),
	v(v),
	angularV(angularV),
	accel(accel)
{
	this->angle = angle;
}

void ComplexBullet::MovePattern()
{
	angle += angularV;
	v += accel;
	if (accel || angularV) CalculateVelocity();

	if (instructions.size() != 0)
	{
		InstructionStruct i = instructions.front();
		while (time == i.time)
		{
			int c = i.setOrChange;
			switch (i.instruction)
			{
			case BULLET_VELOCITY:{v = c*v - (c - 1)*i.data + c*i.data; CalculateVelocity(); } break;
			case BULLET_ANGLE:{angle = c*angle - (c - 1)*i.data + c*i.data; CalculateVelocity(); } break;
			case BULLET_ACCEL:{accel = c*accel - (c - 1)*i.data + c*i.data; } break;
			case BULLET_ANGULAR_VELOCITY:{angularV = c*angularV - (c - 1)*i.data + c*i.data; } break;
			}
			instructions.erase(instructions.begin());
			if (instructions.size() != 0) i = instructions.front(); else break;
		}
	}
}

void ComplexBullet::AddData(int time, int instruction, int setOrChange, double data)
{
	InstructionStruct i = { time, instruction, setOrChange, data };
	instructions.push_back(i);
}

void ComplexBullet::CalculateVelocity()
{
	vx = v*cos((angle)*(M_PI / 180));
	vy = v*sin((angle)*(M_PI / 180));
}
