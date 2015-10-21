#include "grille.h"



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

		for (int y = 0; y < NB_LIGNES; y++)
		{
			for (int x = 0; x < NB_COLONNES; x++)
			{
				char caractere;
				fichier.get(caractere);
				//Remplissage de la matrice de cases, avec des caracteres
				//Ces derniers seront remplacés par des textures dans le mainWindows
				Matrice[x][y] = cases(C[caractere - '0']); 
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
	cout << valTemp << endl;

	return valTemp;
}


void grille::respawnEnnemi()
{

}

void grille::speedEnnemis()
{
	int valDefaut = 100;
}

