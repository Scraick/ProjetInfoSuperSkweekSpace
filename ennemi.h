#ifndef ENNEMI_H
#define ENNEMI_H

class ennemi
{
public:
	ennemi();

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