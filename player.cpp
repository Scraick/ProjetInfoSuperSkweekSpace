#include "player.h"

player joueur (1, 1);

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
		m_playerX -= (0.1 * acceleration());
		deceleration();
	}
}

void player::velocityDroit()
{
	while (deceleration() != 0)
	{
		m_playerX += (0.1 * acceleration());
	}
	deceleration();
}

void player::velocityHaut()
{
	while (deceleration() != 0)
	{
		m_playerY -= (0.1 * acceleration());
	}
	deceleration();
}

void player::velocityBas()
{
	while (deceleration() != 0)
	{
		m_playerY += (0.1 * acceleration());
	}
	deceleration();
}

double player::acceleration()
{
	m_acceleration += 0.015;
	if (m_acceleration > 2)
	{
		m_acceleration = 2;
	}
	return m_acceleration;
}

double player::deceleration()
{
	m_acceleration -= 0.03;
	if (m_acceleration <= 0)
	{
		m_acceleration = 0;
	}
	return m_acceleration;
}

void player::translationCam()
{
	int i = 1;
	glLoadIdentity();

	//if (grilleJeu.m_x < (47 + i)) /*&& (grilleJeu.m_y > 15 /*5*/
		glTranslatef(-m_playerX + 29, -m_playerY + 15.5, 0);

	/*else
		glTranslatef(-grilleJeu.m_x + i, -grilleJeu.m_y + 15.5, 0);*/

	glutSwapBuffers;
}

double player::positionX()
{
	return m_playerX;
}

double player::positionY()
{
	return m_playerY;
}