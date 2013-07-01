#include "../STATES/states.h"

State stateID = State::EMPTY;
State nextState = State::EMPTY;
GameState *currentState = nullptr;

//used code is copied from LazyFoo's tutorial's

void set_next_state( State newState )
{
    if( nextState != State::EXIT )
    {
        nextState = newState;
    }
}


void change_state()
{
    if( nextState != State::EMPTY )
    {
        if( nextState != State::EXIT )
        {
            delete currentState;
        }
        switch( nextState )
        {
            case State::GAME:
                currentState = new Game();
                break;
            case State::MAINMENU:
                currentState = new MainMenu();
                break;
            default:{}
        }
        stateID = nextState;
        nextState = State::EMPTY;
    }
}
