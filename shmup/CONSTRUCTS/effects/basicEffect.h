#pragma once

#include "effect.h"

class BasicEffect : public Effect
{
public:
	BasicEffect(int ntype, double nx, double ny, int nlife);

	void Draw();
protected:
private:
};
