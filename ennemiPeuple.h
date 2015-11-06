#ifndef ENNEMIPEUPLE_H
#define ENNEMIPEUPLE_H
#include "ennemi.h"
#include "grille.h"

class ennemiPeuple : public ennemi
{
public:

	ennemiPeuple(double x, double y);
	
	double positionX();
	double positionY();

	void nombre();
	void changerCase(ennemiPeuple);
	static void deplacementEP(int, ennemiPeuple &);

	void depGauche();
	void depDroit();
	void depHaut();
	void depBas();

	double m_acceleration;
	int valDep = 0;

};

extern ennemiPeuple cargo01;
extern ennemiPeuple cargo02;
extern ennemiPeuple cargo03;

#endif
