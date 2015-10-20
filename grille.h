#ifndef GRILLE_H
#define GRILLE_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "cases.h"

#define NB_LIGNES 20
#define NB_COLONNES 20

using namespace std;

class grille
{

public:
	grille();
	~grille();

	cases Matrice[NB_LIGNES][NB_COLONNES];
	
	void dessinerNiveauBas(vector <cases> C);
};

#endif