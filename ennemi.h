#ifndef ENNEMI_H
#define ENNEMI_H

class ennemi
{
public:
	ennemi();

	ennemi(int x, int y, int val, int numero);

	void mortEnnemi(bool etat); //Vérification de la mort des ennemis
	void deplacementEnnemis(int dep); //Déplacement ennemis
	int tmp = 0;
	double tmpX, tmpY;

	bool m_etat; // booleen d'état de l'ennemi

	void setX(double x);
	void setY(double y);
	void setVal(int val);
	void setNumero(int numero);

	void mort(bool etat);
	void respawn();

	void speed();

	int positionX();
	int positionY();

	int valDep = 0;
	int numeroEnnemi = -1;
	double m_x, m_y;

	void deplacementEP(ennemi &);

protected:
	int  m_nombre; //Position X et Y des différents ennemis
	
};

extern ennemi cargo01;
extern ennemi cargo02;
extern ennemi cargo03;

#endif