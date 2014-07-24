#include "STATES/states.h"
#include "STATES/stages/stages.h"

State nextState = State::EMPTY;

std::stack<std::unique_ptr<GameState>> states;
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
			case State::GAMESTAGE1:
				states.push(std::make_unique<GameStage1>());
				break;
			case State::MAINMENU:
				states.push(std::make_unique<MainMenu>());
				break;
			case State::PAUSE:
				states.push(std::make_unique<Pause>());
				break;
			case State::EXIT:
				states.push(std::make_unique<Exit>());
				break;
			default:{}
		}
		nextState=State::EMPTY;
	}
}

