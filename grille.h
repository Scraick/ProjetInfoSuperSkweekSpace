#ifndef GRILLE_H
#define GRILLE_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

#define NB_LIGNES 20
#define NB_COLONNES 20

using namespace std;

class grille
{

public:
	grille();
	~grille();

	char Matrice[NB_LIGNES][NB_COLONNES];
	
	void dessinerNiveauBas();
};



#endif