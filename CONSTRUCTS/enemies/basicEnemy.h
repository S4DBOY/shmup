#ifndef BASICENEMY_H
#define BASICENEMY_H

#include "enemy.h"

class BasicEnemy : public Enemy
{
    public:
        BasicEnemy(int ntype, double nx, double ny, double nvx, double nvy);
        ~BasicEnemy();

        void Move();
        void Logic();
        void Draw();
    protected:
    private:
};

#endif // BASICENEMY_H
