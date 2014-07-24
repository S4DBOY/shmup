#pragma once

#include <memory>

class BackgroundSet;
class BackgroundManager;
extern BackgroundManager backgroundManager;

class BackgroundManager
{
public:
	void SetBackground();

	void Logic();
	void Draw() const;
protected:
private:
	std::unique_ptr<BackgroundSet> background;
};