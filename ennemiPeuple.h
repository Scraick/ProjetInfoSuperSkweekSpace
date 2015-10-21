#ifndef ENNEMIPEUPLE_H
#define ENNEMIPEUPLE_H
#include "ennemi.h"
#include "grille.h"

class ennemiPeuple : public ennemi
{
public:

	ennemiPeuple();


	
	int positionX();
	int positionY();

	ennemiPeuple(int x, int y);

	void nombre();
	void changerCase();
	//void deplacementEP();


};

#endif