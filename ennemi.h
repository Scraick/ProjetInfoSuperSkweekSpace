#ifndef ENNEMI_H
#define ENNEMI_H

class ennemi
{
public:
	ennemi();

	ennemi(int x, int y);

	void mortEnnemi(bool etat); //V�rification de la mort des ennemis
	void deplacementEnnemis(int dep); //D�placement ennemis


	int m_x, m_y, m_nombre; //Position X et Y des diff�rents ennemis
	bool m_etat; // booleen d'�tat de l'ennemi


	void mort(bool etat);
	void respawn();

	void speed();
	void deplacement(int dep);

	int positionX();
	int positionY();

protected:
	bool m_etat;
	int m_x, m_y, m_nombre;

private:

};

#endif