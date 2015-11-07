#include "sound.h"

sound sons;

sound::sound()
{
}

sound::~sound()
{
}

void sound::music(FMOD_SYSTEM *system, FMOD_SOUND *musique, FMOD_RESULT resultat)
{
	// On vérifie si elle a bien été ouverte
	if (resultat != FMOD_OK)
	{
		exit(10);
	}
	// On répéte la musique à l'infini
	FMOD_Sound_SetLoopCount(musique, -1);
	// On joue la musique
	FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, musique, 0, 0);
}

void sound::bruit()
{
	FMOD_SOUND *tir = NULL;
}

void sound::stop(FMOD_SYSTEM *system, FMOD_SOUND *musique, FMOD_RESULT resultat)
{
	// On libére les sons
	FMOD_Sound_Release(musique);
	FMOD_System_Close(system);
	FMOD_System_Release(system);
}