#pragma once

#include "SFML/graphics.hpp"

class System
{
public:
	System();

	~System();

	void Handle_event(const sf::Event &event);

	bool RegulateFPS();

protected:
	void Setup();

	void ToggleFullscreen();

	float dt;
	sf::Clock clock;

	/*  debugging/performance analysis   */
	int emptyloop;
	int sumEmptyLoops = 0;
	int nSlowDowns = 0;
private:
};

extern System *SFMLsystem;
