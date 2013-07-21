#ifndef STATES_H
#define STATES_H

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
    EXIT
};

/**
    An abstract class for a state. Used only to create subclasses.
*/
class GameState
{
    public:
    virtual void Handle_events() = 0;
    virtual void Logic() = 0;
    virtual void Render() = 0;
    virtual ~GameState(){};
};

extern State stateID;

/**
    \brief prepares to change to the new state. Makes sure that the state won't be changed after setting State::EXIT.
*/
void SetNextState(State newState);

/**
    \brief sets the new state.
*/
void ChangeState();

extern GameState *currentState;

/*class Intro : public GameState
{
    private:

    public:
    Intro();
    ~Intro();

    void Handle_events();
    void Logic();
    void Render();
    private:
};*/

class MainMenu : public GameState
{
    private:

    public:
    MainMenu();
    ~MainMenu();

    void Handle_events();
    void Logic();
    void Render();

    private:
};

class Game : public GameState
{
    private:

    public:
    Game();
    ~Game();

    void Handle_events();
    void Logic();
    void Render();

    private:
};

#endif

