#include "tir.h"

tir bullet;

tir::tir()
{
}

tir::~tir()
{
}

void tir::shoot(int orientation)
{
	int pt1, pt2, pt3, pt4;

	//if ((actif == true) && (speed < 0.2) && (suivant == false))
	//{
		//speed += 0.01f;
		switch (orientation)
		{
		case 0:
			pt1 = round(m_bulletX - 0.4);
			pt2 = round(m_bulletX + 0.4);
			pt3 = round(m_bulletY - 0.6);
			pt4 = round(m_bulletY + 0.4);

			if ((grilleJeu.Matrice[pt3][pt1].m_id != '1') && (grilleJeu.Matrice[pt3][pt2].m_id != '1') && (grilleJeu.Matrice[pt3][pt1].m_id != '3') && (grilleJeu.Matrice[pt3][pt2].m_id != '3'))
			{
				tirHaut();
			}
			break;

		case 1:
			pt1 = round(m_bulletX - 0.2);
			pt2 = round(m_bulletX + 0.2);
			pt3 = round(m_bulletY - 0.4);
			pt4 = round(m_bulletY + 0.6);

			if ((grilleJeu.Matrice[pt3][pt1].m_id != '1') && (grilleJeu.Matrice[pt4][pt1].m_id != '1') && (grilleJeu.Matrice[pt3][pt1].m_id != '3') && (grilleJeu.Matrice[pt4][pt1].m_id != '3'))
			{
				tirGauche();
			}
			break;

		case 2:
			pt1 = round(m_bulletX - 0.2);
			pt2 = round(m_bulletX + 0.2);
			pt3 = round(m_bulletY - 0.4);
			pt4 = round(m_bulletY + 0.6);

			if ((grilleJeu.Matrice[pt4][pt1].m_id != '1') && (grilleJeu.Matrice[pt4][pt2].m_id != '1') && (grilleJeu.Matrice[pt4][pt1].m_id != '3') && (grilleJeu.Matrice[pt4][pt2].m_id != '3'))
			{
				tirBas();
			}
			break;

		case 3:
			pt1 = round(m_bulletX - 0.4);
			pt2 = round(m_bulletX + 0.6);
			pt3 = round(m_bulletY - 0.4);
			pt4 = round(m_bulletY + 0.4);

			if ((grilleJeu.Matrice[pt3][pt2].m_id != '1') && (grilleJeu.Matrice[pt4][pt2].m_id != '1') && (grilleJeu.Matrice[pt3][pt2].m_id != '3') && (grilleJeu.Matrice[pt4][pt2].m_id != '3'))
			{
				tirDroite();
			}
			break;
		}
	//}
	//else
	//{
	//	suivant = true;
	//	speed = 0;
	//	actif = false;
	//}
}

void tir::tirGauche() //Déplacement gauche
{
	m_bulletX -= (0.1);
}

void tir::tirDroite() //Déplacement droit
{
	m_bulletX += (0.1);
}

void tir::tirHaut() //Déplacement haut
{
	m_bulletY -= (0.1);
}

void tir::tirBas() //Déplacement bas
{
	m_bulletY += (0.1);
}

double tir::bulletX()
{
	return m_bulletX;
}

double tir::bulletY()
{
	return m_bulletY;
}

void tir::setX(double x)
{
	m_bulletX = x;
}

void tir::setY(double y)
{
	m_bulletY = y;
}

void tir::setActif(bool a)
{
	actif = a;
}