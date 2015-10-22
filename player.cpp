#include "player.h"

player joueur;


player::player()
{
	
}


player::~player()
{
}


void player::depGauche() //Déplacement gauche
{
	if ((grilleJeu.Matrice[grilleJeu.m_y][grilleJeu.m_x - 1].m_id != '1') && (grilleJeu.Matrice[grilleJeu.m_y][grilleJeu.m_x - 1].m_id != '3')) 
		//Si la valeur de la case n'est pas '1'(trou noir) ou '3'(soleil), alors le déplacement peut se faire
		grilleJeu.m_x--;
}

void player::depDroit() //Déplacement droit
{
	if ((grilleJeu.Matrice[grilleJeu.m_y][grilleJeu.m_x + 1].m_id != '1') && (grilleJeu.Matrice[grilleJeu.m_y][grilleJeu.m_x + 1].m_id != '3'))
		grilleJeu.m_x++;
}

void player::depHaut() //Déplacement haut
{
	if ((grilleJeu.Matrice[grilleJeu.m_y - 1][grilleJeu.m_x].m_id != '1') && (grilleJeu.Matrice[grilleJeu.m_y - 1][grilleJeu.m_x].m_id != '3'))
		grilleJeu.m_y--;

}

void player::depBas() //Déplacement bas
{
	if ((grilleJeu.Matrice[grilleJeu.m_y + 1][grilleJeu.m_x].m_id != '1') && (grilleJeu.Matrice[grilleJeu.m_y + 1][grilleJeu.m_x].m_id != '3'))
		grilleJeu.m_y++;

}

void player::translationCam()
{
	glLoadIdentity();
	glTranslatef(-grilleJeu.m_x + 29, -grilleJeu.m_y + 16, 0);
	glutSwapBuffers;
}
