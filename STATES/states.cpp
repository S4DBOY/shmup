#include "../STATES/states.h"

State stateID = State::EMPTY;
State nextState = State::EMPTY;
GameState *currentState = nullptr;


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
        if(nextState!=State::EXIT)
        {
            if(currentState!=nullptr) delete currentState;
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
        stateID=nextState;
        nextState=State::EMPTY;
    }
}
