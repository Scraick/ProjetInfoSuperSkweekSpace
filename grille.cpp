#include "grille.h"

grille grilleJeu;

grille::grille()
{
	
}

grille::~grille()
{
}

void grille::dessinerNiveauBas(vector <cases> C)
{
	ifstream fichier("Matricetest.txt", ios::in);  // on ouvre le fichier en lecture

	if (fichier)  // si l'ouverture a r�ussi
	{
		char caractere;

		for (int y = 0; y < NB_LIGNES; y++)
		{
			for (int x = 0; x < NB_COLONNES; x++)
			{
				
				fichier.get(caractere);
				//Remplissage de la matrice de cases, avec des caracteres
				//Ces derniers seront remplac�s par des textures dans le mainWindows
				Matrice[y][x] = cases(C[caractere - '0']); 
				cout << caractere;
			}
			
		}

		fichier.close();

	}
	else  // sinon
		cout << "Impossible d'ouvrir le fichier !" << endl;
}

double grille::distancePlanetes()
{
	// Initialisation des valeurs de distance
	int val = 0;
	int valTemp = 100000;

	// Boucle pour la recherche des plan�tes
	for (int i = 0; i < NB_LIGNES; i++)
	{
		for (int j = 0; j < NB_COLONNES; j++)
		{
			if ((Matrice[i][j].m_id == '2') && (planete == 4))
			{
				val = sqrt((ennemiPeuple().positionX() - i) * (ennemiPeuple().positionX() - i) + (ennemiPeuple().positionY() - j) * (ennemiPeuple().positionY() - j)); // Calcul de la distance entre le vaisseau et la plan�te

				if (val < valTemp)
				{
					valTemp = val; // Mise en place d'une valeur temp
				}
			}
		}
	}

	return valTemp;
}


void grille::respawnEnnemi()
{

}

void grille::speedEnnemis()
{
	int valDefaut = 100;
}

void grille::verifPosition()
{

	if (grilleJeu.Matrice[joueur.m_y][joueur.m_x].m_id == '5')
	{
		glutTimerFunc(250, grilleJeu.callBackFleches, 0);
	}


	if (grilleJeu.Matrice[joueur.m_y][joueur.m_x].m_id == '2')
	{
		fenetre.planeteBleuDetruite();
	}

	if (grilleJeu.Matrice[joueur.m_y][joueur.m_x].m_id == '6')
	{
		fenetre.planeteJauneDetruite();
	}

	if (grilleJeu.Matrice[joueur.m_y][joueur.m_x].m_id == '7')
	{
		fenetre.planeteRoseDetruite();
	}
}

void grille::caseFleches()
{
	int alea = (rand() % 4);

	switch (alea)
	{
	case 0:
		if ((grilleJeu.Matrice[joueur.m_y - 1][joueur.m_x].m_id != '1') && (grilleJeu.Matrice[joueur.m_y - 1][joueur.m_x].m_id != '3'))
			//Verification de l'endroit ou les fleches d�placent le joueur
			joueur.m_y--;
		break;

	case 1:
		if ((grilleJeu.Matrice[joueur.m_y + 1][joueur.m_x].m_id != '1') && (grilleJeu.Matrice[joueur.m_y + 1][joueur.m_x].m_id != '3'))
			//Verification de l'endroit ou les fleches d�placent le joueur
			joueur.m_y++;
		break;

	case 2:
		if ((grilleJeu.Matrice[joueur.m_y][joueur.m_x - 1].m_id != '1') && (grilleJeu.Matrice[joueur.m_y][joueur.m_x - 1].m_id != '3'))
			//Verification de l'endroit ou les fleches d�placent le joueur
			joueur.m_x--;
		break;

	case 3:
		if ((grilleJeu.Matrice[joueur.m_y][joueur.m_x + 1].m_id != '1') && (grilleJeu.Matrice[joueur.m_y][joueur.m_x + 1].m_id != '3'))
			//Verification de l'endroit ou les fleches d�placent le joueur
			joueur.m_x++;
		break;
	}

}

void grille::callBackFleches(int call)
{
	grilleJeu.caseFleches();
}
