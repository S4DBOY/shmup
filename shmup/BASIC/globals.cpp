#include "../BASIC/globals.h"

#include <windows.h>

bool FULLSCREEN;
bool FPSLIMIT;
int FRAMES_PER_SECOND;
int SCREEN_WIDTH;
int SCREEN_HEIGHT;

int frameCounter=0;

sf::RenderWindow window;

sf::Event event;

int InitializeGlobals()
{
    FULLSCREEN = (bool)GetPrivateProfileInt("general", "full_screen", 0, ".//config.ini");
    FRAMES_PER_SECOND = GetPrivateProfileInt("general", "frames_per_second", 120, ".//config.ini");
    SCREEN_WIDTH = GetPrivateProfileInt("general", "screen_width", 800, ".//config.ini");
    SCREEN_HEIGHT = GetPrivateProfileInt("general", "screen_height", 600, ".//config.ini");

    return 0;
}
