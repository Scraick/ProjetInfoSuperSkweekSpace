#ifndef ENNEMI_H
#define ENNEMI_H

class ennemi
{
public:
	ennemi();

	ennemi(int x, int y);

	void mortEnnemi(bool etat); //Vérification de la mort des ennemis
	void deplacementEnnemis(int dep); //Déplacement ennemis


	int m_x, m_y, m_nombre; //Position X et Y des différents ennemis
	bool m_etat; // booleen d'état de l'ennemi


	void mort(bool etat);
	void respawn();

	void speed();

	int positionX();
	int positionY();


};

#endif