#include "player.h"

player joueur (1, 1);

player::player(double x, double y)
{
<<<<<<< HEAD
	x = m_playerX;
	y = m_playerY;
=======
	m_x = 1;
	m_y = 1;
>>>>>>> origin/master
}

player::~player()
{
}

void player::depGauche() //Déplacement gauche
{
<<<<<<< HEAD
		m_playerX -= (0.1 * acceleration());
=======
	if ((grilleJeu.Matrice[joueur.m_y][joueur.m_x - 1].m_id != '1') && (grilleJeu.Matrice[joueur.m_y][joueur.m_x - 1].m_id != '3'))
		//Si la valeur de la case n'est pas '1'(trou noir) ou '3'(soleil), alors le déplacement peut se faire
		joueur.m_x--;
>>>>>>> origin/master
}

void player::depDroit() //Déplacement droit
{
<<<<<<< HEAD
		m_playerX += (0.1 * acceleration());
=======
	if ((grilleJeu.Matrice[joueur.m_y][joueur.m_x + 1].m_id != '1') && (grilleJeu.Matrice[joueur.m_y][joueur.m_x + 1].m_id != '3'))
		//Si la valeur de la case n'est pas '1'(trou noir) ou '3'(soleil), alors le déplacement peut se faire
		joueur.m_x++;
>>>>>>> origin/master
}

void player::depHaut() //Déplacement haut
{
<<<<<<< HEAD
		m_playerY -= (0.1 * acceleration());
=======
	if ((grilleJeu.Matrice[joueur.m_y - 1][joueur.m_x].m_id != '1') && (grilleJeu.Matrice[joueur.m_y - 1][joueur.m_x].m_id != '3'))
		//Si la valeur de la case n'est pas '1'(trou noir) ou '3'(soleil), alors le déplacement peut se faire
		joueur.m_y--;
>>>>>>> origin/master
}

void player::depBas() //Déplacement bas
{
<<<<<<< HEAD
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
=======
	if ((grilleJeu.Matrice[joueur.m_y + 1][joueur.m_x].m_id != '1') && (grilleJeu.Matrice[joueur.m_y + 1][joueur.m_x].m_id != '3'))
		//Si la valeur de la case n'est pas '1'(trou noir) ou '3'(soleil), alors le déplacement peut se faire
		joueur.m_y++;
>>>>>>> origin/master
}

void player::translationCam()
{
	int i = 1;
	glLoadIdentity();
<<<<<<< HEAD

	//if (grilleJeu.m_x < (47 + i)) /*&& (grilleJeu.m_y > 15 /*5*/
		glTranslatef(-m_playerX + 29, -m_playerY + 15.5, 0);

	/*else
		glTranslatef(-grilleJeu.m_x + i, -grilleJeu.m_y + 15.5, 0);*/

=======
	glTranslatef(-joueur.m_x + 29, -joueur.m_y + 16, 0);
>>>>>>> origin/master
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
