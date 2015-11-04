#ifndef GRILLE_H
#define GRILLE_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cmath>
#include "cases.h"
#include "mainWindows.h"
#include "ennemiPeuple.h"
#include "player.h"


#define NB_LIGNES 32
#define NB_COLONNES 60

using namespace std;

class grille
{
public:
	grille();
	~grille();

	cases Matrice[NB_LIGNES][NB_COLONNES];

	void dessinerNiveauBas(vector <cases> C);
	double distancePlanetes();

	void respawnEnnemi();
	void speedEnnemis();

	void colisionHaut();
	void colisionBas();
	void colisionGauche();
	void colisionDroite();

	double parallaxeFond(double posX, double posY);

	void verifPosition();
	void caseFleches();
	static void callBackFleches(int call);

private:
	//int planete;

};

extern grille grilleJeu;

#endif