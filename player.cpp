#include "player.h"

player joueur;


player::player()
{
	m_x = 1;
	m_y = 1;
}


player::~player()
{
}


void player::depGauche() //D�placement gauche
{
	if ((grilleJeu.Matrice[joueur.m_y][joueur.m_x - 1].m_id != '1') && (grilleJeu.Matrice[joueur.m_y][joueur.m_x - 1].m_id != '3'))
		//Si la valeur de la case n'est pas '1'(trou noir) ou '3'(soleil), alors le d�placement peut se faire
		joueur.m_x--;
}

void player::depDroit() //D�placement droit
{
	if ((grilleJeu.Matrice[joueur.m_y][joueur.m_x + 1].m_id != '1') && (grilleJeu.Matrice[joueur.m_y][joueur.m_x + 1].m_id != '3'))
		//Si la valeur de la case n'est pas '1'(trou noir) ou '3'(soleil), alors le d�placement peut se faire
		joueur.m_x++;
}

void player::depHaut() //D�placement haut
{
	if ((grilleJeu.Matrice[joueur.m_y - 1][joueur.m_x].m_id != '1') && (grilleJeu.Matrice[joueur.m_y - 1][joueur.m_x].m_id != '3'))
		//Si la valeur de la case n'est pas '1'(trou noir) ou '3'(soleil), alors le d�placement peut se faire
		joueur.m_y--;
}

void player::depBas() //D�placement bas
{
	if ((grilleJeu.Matrice[joueur.m_y + 1][joueur.m_x].m_id != '1') && (grilleJeu.Matrice[joueur.m_y + 1][joueur.m_x].m_id != '3'))
		//Si la valeur de la case n'est pas '1'(trou noir) ou '3'(soleil), alors le d�placement peut se faire
		joueur.m_y++;
}

void player::translationCam()
{
	glLoadIdentity();
	glTranslatef(-joueur.m_x + 29, -joueur.m_y + 16, 0);
	glutSwapBuffers;
}
