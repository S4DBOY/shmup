#pragma once

#include <stack>
#include <memory>

class BulletManager;
class EnemyManager;
class EffectManager;
class Player;

namespace sf{ class Event; }

enum class State
{
	EMPTY,
	INTRO,
	MAINMENU,
	GAME,
	GAMESTAGE1,
	PAUSE,
	EXIT
};

class GameState
{
public:
	virtual void Handle_events(const sf::Event &event){};
	virtual void Logic() = 0;
	virtual void Render() const = 0;
	virtual ~GameState(){};
protected:
	int stateFrameCounter = 0;
};

extern bool done;

void SetNextState(State newState);

void ChangeState();

extern std::stack<std::unique_ptr<GameState>> states;

/*class Intro : public GameState
{
public:
Intro();
~Intro();
void Handle_events(const sf::Event &event);
void Logic();
void Render();
};*/
class MainMenu : public GameState
{
public:
	MainMenu();
	~MainMenu();
	void Handle_events(const sf::Event &event);
	void Logic();
	void Render() const;
};
class Game : public GameState
{
public:
	Game();
	virtual ~Game();
	void Handle_events(const sf::Event &event);
	void Logic();
	void Render() const;
private:
	virtual void StageLogic(){};
};

class Pause : public GameState
{
public:
	Pause();
	~Pause();
	void Handle_events(const sf::Event &event);
	void Logic();
	void Render() const;
};
class Exit : public GameState
{
public:
	void Logic();
	void Render() const;
};