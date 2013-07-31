#include "../STATES/states.h"

State nextState = State::EMPTY;

std::stack<GameState*> states;
bool done=0;


void SetNextState(State newState)
{
    if( nextState!=State::EXIT )
    {
        nextState=newState;
    }
}

void ChangeState()
{
    if(nextState!=State::EMPTY)
    {
        switch( nextState )
        {
            case State::GAME:
                states.push(new Game());
                break;
            case State::MAINMENU:
                states.push(new MainMenu());
                break;
            case State::PAUSE:
                states.push(new Pause());
                break;
            case State::EXIT:
                states.push(new Exit());
                break;
            default:{}
        }
        nextState=State::EMPTY;
    }
}

