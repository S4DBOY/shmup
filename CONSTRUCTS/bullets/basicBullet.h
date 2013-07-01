#ifndef BASICBULLET_H
#define BASICBULLET_H

#include "bullet.h"

class BasicBullet : public Bullet
{
    public:
        BasicBullet(int ntype, double nx, double ny, double nv, double nangle);
        ~BasicBullet();
    protected:
    private:
};

#endif // BASICBULLET_H
