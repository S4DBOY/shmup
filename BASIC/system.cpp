#include "../BASIC/system.h"

#include "../BASIC/globals.h"
#include "../RESOURCES/images.h"
#include "../RESOURCES/sound.h"
#include "../STATES/states.h"

#include <ctime>
#include <sstream>      //to be deleted in release
#include <fstream>      //to be deleted in release
#include <cstdlib>

System *SFMLsystem;

std::ofstream debugData ("debugData.txt");

System::System()
{
    InitializeGlobals();
    if(Setup()==1)  stateID = State::EXIT;
    LoadImages();
    LoadSounds();

    clock.restart();
}

System::~System()
{
    window.close();

        /*          performance data            */
    debugData<<std::endl;
    debugData<<"resolution: "<<SCREEN_WIDTH<<"/"<<SCREEN_HEIGHT<<", "<<FRAMES_PER_SECOND<<", fullscreen: "<<FULLSCREEN<<std::endl;
    debugData<<std::endl;
    debugData<<sumEmptyLoops/(frameCounter-120)<<" empty loops per frame on average"<<std::endl;
    debugData<<nSlowDowns<<" slowdowns, "<<60*nSlowDowns/(frameCounter-120.0)<<" per sec"<<std::endl;
    debugData<<"program lasted for "<<frameCounter<<" frames"<<std::endl;
    debugData.close();
}

bool System::RegulateFPS()
{
    dt = clock.getElapsedTime().asSeconds();
    if(dt<=1.0/(FRAMES_PER_SECOND)) {emptyloop++; return 1;}
    if (dt > 0.1) dt = 0.0016;
    clock.restart();

        /*     FPS counter     */
    std::ostringstream performance;
    performance << 1/dt<<" "<<emptyloop;
    window.setTitle(performance.str());

    if(frameCounter>120) sumEmptyLoops+=emptyloop;
    if(frameCounter>120 && 1/dt<59.9) {debugData<<"frame "<<frameCounter<<" , "<<emptyloop<<" "<<1/dt<<std::endl; nSlowDowns++;}

    emptyloop=0;
    return 0;
}

void System::Handle_events()
{
    if( event.type ==  sf::Event::Closed ) {SetNextState(State::EXIT); return;}
    if( event.type == sf::Event::KeyPressed )
    {
        if(event.key.code == sf::Keyboard::F4 && event.key.alt )
            {SetNextState(State::EXIT); return;}
        if(event.key.code == sf::Keyboard::Return && event.key.alt)
            ToggleFullscreen();
    }
    if(event.type==sf::Event::LostFocus)    //makeshift fix for SFML fullscreen window behavior when alt-tabbing
    {
        if(FULLSCREEN) ToggleFullscreen();
    }
}


void System::ToggleFullscreen()
{
    FULLSCREEN=!FULLSCREEN;
    window.close();

    if(FULLSCREEN) window.create( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, 32 ), "TEST SFML", sf::Style::Fullscreen );
    else window.create( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, 32 ), "TEST SFML", sf::Style::Titlebar );
    //window.setMouseCursorVisible(0);
}


bool System::Setup()
{
    if(FULLSCREEN) window.create( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, 32 ), "TEST SFML", sf::Style::Fullscreen );
    else window.create( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, 32 ), "TEST SFML");

    window.setPosition(sf::Vector2i{0, 0});

    //window.setMouseCursorVisible(0);

    srand(time(0));
    return 0;
}
