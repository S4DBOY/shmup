#ifndef BACKGROUNDSET
#define BACKGROUNDSET

class BackgroundSet
{
    public:
        BackgroundSet(){};
        virtual ~BackgroundSet(){};
        virtual void Logic()=0;
        virtual void Draw()=0;
};

#endif
