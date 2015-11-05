#include "player.h"

player joueur(1, 1);

player::player(double x, double y)
{
	x = m_playerX;
	y = m_playerY;
}

player::~player()
{
}

void player::depGauche() //Déplacement gauche
{
	m_playerX -= (0.1 * acceleration());
}

void player::depDroit() //Déplacement droit
{
	m_playerX += (0.1 * acceleration());
}

void player::depHaut() //Déplacement haut
{
	m_playerY -= (0.1 * acceleration());
}

void player::depBas() //Déplacement bas
{
	m_playerY += (0.1 * acceleration());
}

void player::velocityGauche()
{
	while (deceleration() != 0)
	{
		grilleJeu.colisionGauche();
		deceleration();
	}
}

void player::velocityDroit()
{
	while (deceleration() != 0)
	{
		grilleJeu.colisionDroite();
		deceleration();
	}
}

void player::velocityHaut()
{
	while (deceleration() != 0)
	{
		grilleJeu.colisionHaut();
		deceleration();
	}
}

void player::velocityBas()
{
	while (deceleration() != 0)
	{
		grilleJeu.colisionBas();
		deceleration();
	}
}

double player::acceleration()
{
	m_acceleration += 0.03;
	if (m_acceleration > 2)
	{
		m_acceleration = 2;
	}
	return m_acceleration;
}

double player::deceleration()
{
	m_acceleration -= 0.06;
	if (m_acceleration <= 0)
	{
		m_acceleration = 0;
	}
	return m_acceleration;
}

double player::positionX()
{
	return m_playerX;
}

double player::positionY()
{
	return m_playerY;
}