#include "basicEffect.h"

#include "RESOURCES/images.h"

BasicEffect::BasicEffect(int ntype, double nx, double ny, int nlife) :
	Effect(ntype, nx, ny, nlife)
{
	time = 0;
}

void BasicEffect::Draw()
{
	time++;
}
