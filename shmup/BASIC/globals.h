#ifndef GLOBALS_H
#define GLOBALS_H

#include "SFML/graphics.hpp"

extern bool FULLSCREEN;
extern int  FRAMES_PER_SECOND;
extern int  SCREEN_WIDTH;
extern int  SCREEN_HEIGHT;

extern sf::RenderWindow window;

extern sf::Event event;

extern int frameCounter;

/**
    \brief Loads configuration data from the config file.
    Currently uses Windows API functions, I may search for an cross-platform solution in the future.
*/
int InitializeGlobals();


#endif // GLOBALS_H
