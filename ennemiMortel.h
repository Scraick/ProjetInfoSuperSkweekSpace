#ifndef ENNEMIMORTEL_H
#define ENNEMIMORTEL_H
#include "ennemi.h"

class ennemiMortel : public ennemi
{
public:
	ennemiMortel();

	int nombre();
	void tuer();

	bool invisible();
	void deplacement();

private:
	bool m_invisible;
};

#endif