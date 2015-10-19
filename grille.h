#ifndef GRILLE_H
#define GRILLE_H
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class grille
{

	

public:
	grille();
	~grille();

	
	void dessinerNiveauBas();
};

extern string Matrice[20][20];

#endif