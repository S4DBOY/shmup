#ifndef BASICBULLET_H
#define BASICBULLET_H

#include "bullet.h"

/**
    \brief A a simple bullet, the only difference from its parent being the construction arguments.
*/
class BasicBullet : public Bullet
{
    public:
        BasicBullet(std::string ntype, double nx, double ny, double nv, double nangle);
        ~BasicBullet(){};
    protected:
    private:
};

#endif // BASICBULLET_H
