#include "grille.h"


grille::grille()
{
}


grille::~grille()
{
}


void grille::dessinerNiveauBas()
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
				Matrice[x][y] = caractere;
			}
		}

		fichier.close();

		for (int y = 0; y < NB_LIGNES; y++)
		{
			for (int x = 0; x < NB_COLONNES; x++)
			{
				cout << Matrice[x][y];
			}
			cout << '\n';
		}

	}
	else  // sinon
		cout << "Impossible d'ouvrir le fichier !" << endl;

}
