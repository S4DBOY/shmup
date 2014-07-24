#pragma once

class Effect
{
public:
	Effect(int ntype, double nx, double ny, int nlife) :
		type(ntype), x(nx), y(ny), life(nlife) {};
	virtual ~Effect() {};

	virtual void Draw() = 0;
	bool isDead() const
		{ return time > life; }

protected:
	int type;
	double x, y;
	int time, life;

private:
};