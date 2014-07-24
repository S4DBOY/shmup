#pragma once

#include "bullet.h"
#include <vector>

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

class ComplexBullet : public Bullet
{
public:
	ComplexBullet(const std::string & type,
		double x, double y,
		double v, double angle, double angularV,
		double accel);
	~ComplexBullet(){};

	void AddData(int time, int instruction, int setOrChange, double data);
protected:
private:
	void MovePattern();
	double v;
	double angularV;
	double accel;
	std::vector<InstructionStruct> instructions;

	void CalculateVelocity();
};