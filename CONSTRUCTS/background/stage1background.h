#ifndef STAGE1BACKGROUND_H
#define STAGE1BACKGROUND_H

#include "backgroundSet.h"

class Stage1 : public BackgroundSet
{
    public:
        Stage1(){};
        ~Stage1(){};
        void Logic();
        void Draw();
};

#endif
