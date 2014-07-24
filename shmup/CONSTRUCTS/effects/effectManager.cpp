#include "effectManager.h"

#include "basicEffect.h"

EffectManager effectManager;

void EffectManager::Logic()
{
	for (unsigned int i = 0; i < effects.size(); ++i)
	{
		//if(effects[i]->time>effects[i]->life)  {effects.erase(effects.begin()+i); i=i-1;}
	}
}

void EffectManager::Draw() const
{
	for (auto& effect : effects)
		effect->Draw();
}

void EffectManager::AddEffect(int type, double x, double y)
{
	effects.push_back(std::make_unique<BasicEffect>(type, x, y, 5));
}
