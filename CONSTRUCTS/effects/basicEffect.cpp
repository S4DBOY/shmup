#include "basicEffect.h"

#include "../../BASIC/globals.h"
#include "../../RESOURCES/images.h"

BasicEffect::BasicEffect(int ntype, double nx, double ny, int nlife):
    Effect(ntype, nx, ny, nlife)
{
    time=0;
    loc.x=x; loc.y=y;
    loc.w=5; loc.h=5;
}

BasicEffect::~BasicEffect()
{
    //dtor
}

void BasicEffect::Draw()
{
    time++;
    SDL_RenderFillRect(ren, &loc);
}
