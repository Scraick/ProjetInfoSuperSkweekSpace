#ifndef SOUND_H
#define SOUND_H

#include <string>
#include "FMOD\fmod.h"

class sound
{
public:
	sound();
	~sound();

	static void music();
};
extern sound sons;
#endif