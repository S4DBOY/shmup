#ifndef SOUND_H
#define SOUND_H

void InitSoundLibrary();
void CloseSoundLibrary();

/**
\brief Loads all sound files.
*/
void LoadSounds();

/**
\brief Frees sound memory.
*/
void UnloadSounds();

#endif // SOUND_H
