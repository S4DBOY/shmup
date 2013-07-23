#include "sound.h"

#include "SDL2/SDL_mixer.h"

void InitSoundLibrary()
{
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 512 );
}

void CloseSoundLibrary()
{
    Mix_CloseAudio();
}

void LoadSounds()
{

}

void UnloadSounds()
{

}
