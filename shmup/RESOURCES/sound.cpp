#include "sound.h"

#include "SFML/Audio.hpp"
#include <vector>
#include <queue>

std::vector<sf::SoundBuffer> samples;
std::queue<sf::Sound> sounds;

sf::Music placeholder;


void LoadSounds()
{

}

void CleanSounds()
{
    if(sounds.empty()) return;
    if(sounds.front().getStatus()==sf::Sound::Stopped) sounds.pop();
}

void PlaySound(int name)
{
    sounds.push(sf::Sound(samples[name]));
    sounds.back().play();
}
