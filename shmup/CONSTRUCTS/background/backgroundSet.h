#pragma once

class BackgroundSet
{
public:
	BackgroundSet(){};
	virtual ~BackgroundSet(){};
	virtual void Logic() = 0;
	virtual void Draw() const = 0;
};
