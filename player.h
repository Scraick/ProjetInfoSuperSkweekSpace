#ifndef PLAYER_H
#define PLAYER_H
#include "grille.h"
#include <ctime>

class player
{
public:



	player(double x, double y);
	~player();

	int valDep = 0;

	void depGauche();
	void depDroit();
	void depHaut();
	void depBas();

	void velocityGauche();
	void velocityDroit();
	void velocityHaut();
	void velocityBas();

	double acceleration();
	double deceleration();

	double positionX();
	double positionY();

private:

	int m_nbVie;
	double m_playerX = 1;
	double m_playerY = 1;
	double m_acceleration;
};

extern player joueur;
#endif