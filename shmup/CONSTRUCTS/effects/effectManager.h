#pragma once

#include <vector>
#include <memory>

class Effect;
class EffectManager;
extern EffectManager effectManager;

enum EFFECT_TYPE{
	EF_EFFECT1
};

class EffectManager
{
public:
	void Logic();
	void Draw() const;
	void AddEffect(int type, double x, double y);
protected:
private:
	std::vector<std::unique_ptr<Effect>> effects;
};