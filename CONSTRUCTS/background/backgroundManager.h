#ifndef BACKGROUNDMANAGER_H
#define BACKGROUNDMANAGER_H

class BackgroundSet;
class BackgroundManager;
extern BackgroundManager backgroundManager;

class BackgroundManager
{
    public:
        BackgroundManager();
        ~BackgroundManager();

        void SetBackground();

        void Logic();
        void Draw();
    protected:
    private:
        BackgroundSet *background;
};

#endif
