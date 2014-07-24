#pragma once

#include "SFML/graphics.hpp"

extern bool FULLSCREEN;
extern int  FRAMES_PER_SECOND;
extern int  SCREEN_WIDTH;
extern int  SCREEN_HEIGHT;

extern sf::RenderWindow window;

extern int frameCounter;

int InitializeGlobals();
