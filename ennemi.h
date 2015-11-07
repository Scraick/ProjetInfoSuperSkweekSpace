#ifndef ENNEMI_H
#define ENNEMI_H

class ennemi
{
public:
	ennemi();

	ennemi(int x, int y, int val);

	void mortEnnemi(bool etat); //V�rification de la mort des ennemis
	void deplacementEnnemis(int dep); //D�placement ennemis
	int tmp = 0;
	double tmpX, tmpY;

	bool m_etat; // booleen d'�tat de l'ennemi

	void setX(double x);
	void setY(double y);
	void setVal(int val);

	void mort(bool etat);
	void respawn();

	void speed();

	int positionX();
	int positionY();

	int valDep = 0;
	double m_x, m_y;

	void deplacementEP(ennemi &);

protected:
	int  m_nombre; //Position X et Y des diff�rents ennemis
	
};

extern ennemi cargo01;
extern ennemi cargo02;
extern ennemi cargo03;

#endif