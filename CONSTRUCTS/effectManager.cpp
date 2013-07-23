#include "managers.h"

#include "../CONSTRUCTS/effects/basicEffect.h"

EffectManager effectManager;

EffectManager::EffectManager()
{
    //ctor
}

EffectManager::~EffectManager()
{
    effects.clear();
}

void EffectManager::Logic()
{
    for(unsigned int i=0; i<effects.size(); ++i)
    {
        //if(effects[i]->time>effects[i]->life)  {effects.erase(effects.begin()+i); i=i-1;}
    }
}

void EffectManager::Draw()
{
    for(unsigned int i=0; i<effects.size(); ++i){ effects[i]->Draw();}
}

void EffectManager::AddEffect(int type, double x, double y)
{
    effects.push_back(std::unique_ptr<BasicEffect>(new BasicEffect(type, x, y, 5)));
}
