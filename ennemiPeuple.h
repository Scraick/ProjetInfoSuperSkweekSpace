#ifndef ENNEMIPEUPLE_H
#define ENNEMIPEUPLE_H
#include "ennemi.h"
#include "grille.h"

class ennemiPeuple : public ennemi
{
public:
	ennemiPeuple(int x, int y);

	void nombre();

	double distance();
	//	void deplacement();
	void changerCase();

private:
	int planete;

};

#endif