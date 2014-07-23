#ifndef BASICEFFECT_H
#define BASICEFFECT_H

#include "effect.h"

class BasicEffect:public Effect
{
    public:
        BasicEffect(int ntype, double nx, double ny, int nlife);
        ~BasicEffect();

        void Draw();
    protected:
    private:
};

#endif // BASICEFFECT_H
