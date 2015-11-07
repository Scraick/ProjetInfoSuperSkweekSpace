#ifndef ENNEMIPEUPLE_H
#define ENNEMIPEUPLE_H
#include "ennemi.h"
#include "grille.h"

class ennemiPeuple : public ennemi
{
public:

	ennemiPeuple();

	double positionX();
	double positionY();

	void nombre();

	double m_acceleration;
};

#endif