#ifndef STATES_H
#define STATES_H

class BulletManager;
class EnemyManager;
class EffectManager;
class Player;

enum class State
{
    EMPTY,
    INTRO,
    MAINMENU,
    GAME,
    EXIT
};

class GameState
{
    public:
    virtual void Handle_events() = 0;
    virtual void Logic() = 0;
    virtual void Render() = 0;
    virtual ~GameState(){};
};

extern State stateID;
extern State nextState;

void set_next_state( int newState );
void change_state();

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

