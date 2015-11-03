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

	if (fichier)  // si l'ouverture a réussi
	{
		char caractere;

		for (int y = 0; y < NB_LIGNES; y++)
		{
			for (int x = 0; x < NB_COLONNES; x++)
			{
				
				fichier.get(caractere);
				//Remplissage de la matrice de cases, avec des caracteres
				//Ces derniers seront remplacés par des textures dans le mainWindows
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

	// Boucle pour la recherche des planétes
	for (int i = 0; i < NB_LIGNES; i++)
	{
		for (int j = 0; j < NB_COLONNES; j++)
		{
			if ((Matrice[i][j].m_id == '2') && (planete == 4))
			{
				val = sqrt((ennemiPeuple().positionX() - i) * (ennemiPeuple().positionX() - i) + (ennemiPeuple().positionY() - j) * (ennemiPeuple().positionY() - j)); // Calcul de la distance entre le vaisseau et la planéte

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

void grille::colisionHaut()
{
	int	pt1 = round(joueur.positionX() - 0.4);
	int	pt2 = round(joueur.positionX() + 0.4);
	int	pt3 = round(joueur.positionY() - 0.6);
	int	pt4 = round(joueur.positionY() + 0.4);

	if ((grilleJeu.Matrice[pt3][(int)pt1].m_id != '1') && (grilleJeu.Matrice[pt3][(int)pt2].m_id != '1'))
	{
		joueur.depHaut();
	}
}

void grille::colisionBas()
{
	int pt1 = round(joueur.positionX() - 0.2);
	int pt2 = round(joueur.positionX() + 0.2);
	int pt3 = round(joueur.positionY() - 0.4);
	int pt4 = round(joueur.positionY() + 0.6);

	if ((grilleJeu.Matrice[pt4][(int)pt1].m_id != '1') && (grilleJeu.Matrice[pt4][(int)pt2].m_id != '1'))
	{
		joueur.depBas();
	}
}

void grille::colisionGauche()
{
	int pt1 = round(joueur.positionX() - 0.6);
	int pt2 = round(joueur.positionX() + 0.4);
	int pt3 = round(joueur.positionY() - 0.4);
	int pt4 = round(joueur.positionY() + 0.4);

	if ((grilleJeu.Matrice[(int)pt3][pt1].m_id != '1') && (grilleJeu.Matrice[pt4][(int)pt1].m_id != '1'))
	{
		joueur.depGauche();
	}
}

void grille::colisionDroite()
{
	int pt1 = round(joueur.positionX() - 0.4);
	int pt2 = round(joueur.positionX() + 0.6);
	int pt3 = round(joueur.positionY() - 0.4);
	int pt4 = round(joueur.positionY() + 0.4);

	if ((grilleJeu.Matrice[(int)pt3][pt2].m_id != '1') && (grilleJeu.Matrice[(int)pt4][pt2].m_id != '1'))
	{
		joueur.depDroit();
	}
}
