#ifndef ENNEMIMORTEL_H
#define ENNEMIMORTEL_H
#include "ennemi.h"

class ennemiMortel : public ennemi
{
public:
	ennemiMortel();


	int nombre(); //Nombre d'ennemis Mortel
	void tuer(); //Fonction pour tuer le joueur

	bool invisible(); // Booleen pour verifier si le joueur est invisible ou non
	void deplacementMortel(); //Deplacement ennemis Mortel

	bool m_invisible;
};

#endif