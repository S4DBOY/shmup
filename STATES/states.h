#ifndef STATES_H
#define STATES_H

#include <stack>
#include <memory>

class BulletManager;
class EnemyManager;
class EffectManager;
class Player;

/**
    \brief holds all the possible program states.
*/
enum class State
{
    EMPTY,
    INTRO,
    MAINMENU,
    GAME,
    PAUSE,
    EXIT
};

/**
    An abstract class for a state. Used only to create subclasses.
*/
class GameState
{
    public:
        virtual void Handle_events(){};
        virtual void Logic(){};
        virtual void Render(){};
        virtual ~GameState(){};
    protected:
        int stateFrameCounter=0;
};

extern bool done;

/**
    \brief prepares to change to the new state. Makes sure that the state won't be changed after setting State::EXIT.
*/
void SetNextState(State newState);

/**
    \brief sets the new state.
*/
void ChangeState();

extern std::stack<GameState*> states;

/*class Intro : public GameState
{
    public:
    Intro();
    ~Intro();
    void Handle_events();
    void Logic();
    void Render();
};*/
class MainMenu : public GameState
{
    public:
    MainMenu();
    ~MainMenu();
    void Handle_events();
    void Logic();
    void Render();
};
class Game : public GameState
{
    public:
    Game();
    ~Game();
    void Handle_events();
    void Logic();
    void Render();
};
class Pause : public GameState
{
    public:
    Pause();
    ~Pause();
    void Handle_events();
    void Logic();
    void Render();
};
class Exit : public GameState
{
    public:
    void Logic();
    void Render();
};

#endif
