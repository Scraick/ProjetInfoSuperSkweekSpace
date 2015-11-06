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
	int tmp;
	tmp = orientation;

	if (!bulletActif())
		m_orientation = tmp;

		switch (m_orientation)
		{
		case 0:
			pt1 = round(m_bulletX - 0.4);
			pt2 = round(m_bulletX + 0.4);
			pt3 = round(m_bulletY - 0.6);
			pt4 = round(m_bulletY + 0.4);

			if ((grilleJeu.Matrice[pt3][pt1].m_id != '1') && (grilleJeu.Matrice[pt3][pt2].m_id != '1') && (grilleJeu.Matrice[pt3][pt1].m_id != '3') && (grilleJeu.Matrice[pt3][pt2].m_id != '3') && (m_speed < 2))
			{
				m_speed += 0.01;
				m_bulletY -= (m_speed);
			}
			else
			{
				bullet.setActif(false);
				m_speed = 0;
			}
			break;

		case 1:
			pt1 = round(m_bulletX - 0.2);
			pt2 = round(m_bulletX + 0.2);
			pt3 = round(m_bulletY - 0.4);
			pt4 = round(m_bulletY + 0.6);

			if ((grilleJeu.Matrice[pt3][pt1].m_id != '1') && (grilleJeu.Matrice[pt4][pt1].m_id != '1') && (grilleJeu.Matrice[pt3][pt1].m_id != '3') && (grilleJeu.Matrice[pt4][pt1].m_id != '3') && (m_speed < 2))
			{
				m_speed += 0.01;
				m_bulletX -= (m_speed);
			}
			else
			{
				bullet.setActif(false);
				m_speed = 0;
			}
			break;

		case 2:
			pt1 = round(m_bulletX - 0.2);
			pt2 = round(m_bulletX + 0.2);
			pt3 = round(m_bulletY - 0.4);
			pt4 = round(m_bulletY + 0.6);

			if ((grilleJeu.Matrice[pt4][pt1].m_id != '1') && (grilleJeu.Matrice[pt4][pt2].m_id != '1') && (grilleJeu.Matrice[pt4][pt1].m_id != '3') && (grilleJeu.Matrice[pt4][pt2].m_id != '3') && (m_speed < 2))
			{
				m_speed += 0.01;
				m_bulletY += (m_speed);
			}
			else
			{
				bullet.setActif(false);
				m_speed = 0;
			}
			break;

		case 3:
			pt1 = round(m_bulletX - 0.4);
			pt2 = round(m_bulletX + 0.6);
			pt3 = round(m_bulletY - 0.4);
			pt4 = round(m_bulletY + 0.4);

			if ((grilleJeu.Matrice[pt3][pt2].m_id != '1') && (grilleJeu.Matrice[pt4][pt2].m_id != '1') && (grilleJeu.Matrice[pt3][pt2].m_id != '3') && (grilleJeu.Matrice[pt4][pt2].m_id != '3') && (m_speed < 2))
			{
				m_speed += 0.01;
				m_bulletX += (m_speed);
			}
			else
			{
				bullet.setActif(false);
				m_speed = 0;
			}
			break;
		}
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
	m_actif = a;
}

bool tir::bulletActif()
{
	return m_actif;
}