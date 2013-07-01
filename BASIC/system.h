#ifndef SYSTEM_H
#define SYSTEM_H

#include "../BASIC/globals.h"


class System
{
    public:
        System();
        ~System();
        void Input();

        bool RegulateFPS();
    protected:
        bool Setup();
        void ToggleFullscreen();
        SDL_Window *window;

        uint64_t now, old;
        double dt;
        int emptyloop;
    private:
};

extern System *SDLsystem;

#endif // SYSTEM_H
