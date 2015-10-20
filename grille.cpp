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
				Matrice[x][y] = cases(C[caractere - '0']);
			}
		}

		fichier.close();

	}
	else  // sinon
		cout << "Impossible d'ouvrir le fichier !" << endl;

}
