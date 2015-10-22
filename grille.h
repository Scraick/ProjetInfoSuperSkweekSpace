#ifndef GRILLE_H
#define GRILLE_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "cases.h"
#include "mainWindows.h"
#include "ennemiPeuple.h"


#define NB_LIGNES 32
#define NB_COLONNES 60

using namespace std;

class grille
{
private :
	int planete;

public:
	grille();
	~grille();

	cases Matrice[NB_LIGNES][NB_COLONNES];

	int m_x = 1, m_y = 1; //Position de départ du joueur

	void dessinerNiveauBas(vector <cases> C);
	double distancePlanetes();
	void respawnEnnemi();
	void speedEnnemis();

	void verifPosition();
	void caseFleches();
	static void callBackFleches(int call);

};

extern grille grilleJeu;

#endif