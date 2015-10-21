#ifndef ENNEMIPEUPLE_H
#define ENNEMIPEUPLE_H
#include "ennemi.h"
#include "grille.h"

class ennemiPeuple : public ennemi
{
public:
	ennemiPeuple();

	//void deplacementEP();
	
	int positionX();
	int positionY();
};

#endif