#include "ennemi.h"

ennemi::ennemi() : m_etat(true)
{
}

void ennemi::speed()
{
	int valDefaut = 100;
}

void ennemi::mort(bool etat)
{
	m_etat = etat;
	etat = false;
}

void ennemi::respawn()
{

}

void ennemi::deplacement(int dep)
{
	int x, y;
	x = m_x;
	y = m_y;

	switch (dep)
	{
	case 0: x++;
		break;
	case 1: x--;
		break;
	case 2: y++;
		break;
	case 3: y--;
		break;
	}
	m_y = y;
	m_x = x;
}

int ennemi::positionX()
{
	return m_x;
}
int ennemi::positionY()
{
	return m_y;
}