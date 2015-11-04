//#include "sound.h"
//
//sound::sound()
//{
//}
//
//sound::~sound()
//{
//}
//
//void sound::music()
//{
//	// Initialisation de la musique
//	FMOD_SYSTEM *system;
//	FMOD_SOUND *musique;
//	FMOD_RESULT resultat;
//	FMOD_System_Create(&system);
//	FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, 0);
//
//	// On ouvre la musique
//	resultat = FMOD_System_CreateSound(system, "sounds/Main_Theme.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &musique);
//	// On vérifie si elle a bien été ouverte
//	if (resultat != FMOD_OK)
//	{
//		exit(10);
//	}
//	// On répéte la musique à l'infini
//	FMOD_Sound_SetLoopCount(musique, -1);
//	// On joue la musique
//	FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, musique, 0, 0);
//
//	// On libére les sons
//	FMOD_Sound_Release(musique);
//	FMOD_System_Close(system);
//	FMOD_System_Release(system);
//}