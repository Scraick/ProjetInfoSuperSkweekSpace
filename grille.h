#ifndef GRILLE_H
#define GRILLE_H
#include <fstream>
#include <sstream>
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

extern char Matrice[20][20];

#endif