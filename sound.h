#ifndef SOUND_H
#define SOUND_H
#include <string>
#include "FMOD\fmod.h"

class sound
{
public:
	sound();
	~sound();

	static void music(FMOD_SYSTEM *system, FMOD_SOUND *musique, FMOD_RESULT resultat);
	static void bruit();
	static void stop(FMOD_SYSTEM *system, FMOD_SOUND *musique, FMOD_RESULT resultat);
};
extern sound sons;
#endif