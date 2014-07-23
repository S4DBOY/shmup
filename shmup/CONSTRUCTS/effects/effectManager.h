#ifndef EFFECTMANAGER_H
#define EFFECTMANAGER_H

#include <vector>
#include <memory>

class Effect;
class EffectManager;
extern EffectManager effectManager;

/**
    \brief List of possible effect types, which determine their graphics and behaviour
*/
enum EFFECT_TYPE{
    EF_EFFECT1
};

/**
    \brief A wrapper for a Effect type vector
*/
class EffectManager
{
    public:
        EffectManager();
        ~EffectManager();

        void Logic();
        void Draw();
        void AddEffect(int type, double x, double y);
    protected:
    private:
        std::vector<std::unique_ptr<Effect>> effects;
};

#endif
