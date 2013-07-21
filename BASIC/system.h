#ifndef SYSTEM_H
#define SYSTEM_H

#include "SDL2/SDL.h"

/**
    \brief A wrapper for SDL window handling, FPS control and resource initialization/destruction.
*/
class System
{
    public:
        /**
            \brief Does all the initialization before the game loop begins.
        */
        System();

        /**
            \brief Cleans up.
            Frees all textures and audio, deleted managers, closes SDL.
            Also, creates a performance analysis file.
        */
        ~System();

        /**
            \brief Handles all events that should be handled in every possible state.
        */
        void Handle_events();

        /**
            \brief Makes the program wait until the exact time has passed.
            Also, prints the FPS to the window title.
        */
        bool RegulateFPS();
    protected:
        /**
            \brief Initializes SDL and all important subsystems
        */
        bool Setup();

        /**
            \brief Reloads all resources and changes the window type to fullscreen.
        */
        void ToggleFullscreen();

        SDL_Window *window;

        uint64_t now, old;
        double dt;

        /*  debugging/performance analysis   */
        int emptyloop;
        int sumEmptyLoops=0;
        int nSlowDowns=0;
    private:
};

extern System *SDLsystem;

#endif // SYSTEM_H
