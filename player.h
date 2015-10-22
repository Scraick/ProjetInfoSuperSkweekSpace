#ifndef PLAYER_H
#define PLAYER_H
#include "grille.h"


class player
{
public:
	player();
	~player();

	int valDep = 0;

	void depGauche();
	void depDroit();
	void depHaut();
	void depBas();

	void translationCam();

protected:
	int m_nbVie;
};

extern player joueur;
#endif