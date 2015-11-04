#ifndef TIR_H
#define TIR_H

#include "grille.h"

class tir
{
public:
	tir();
	~tir();

	void shoot(int orientation);

	void tirHaut();
	void tirBas();
	void tirDroite();
	void tirGauche();

	double bulletX();
	double bulletY();
	void setX(double x);
	void setY(double y);
	void setActif(bool a);

private:
	double m_bulletX;
	double m_bulletY;
	double speed = 0;
	bool actif = false;
	bool suivant = true;
};
extern tir bullet;
#endif