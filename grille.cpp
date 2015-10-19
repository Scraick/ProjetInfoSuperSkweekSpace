#include "grille.h"

const int Nbligne = 20;
const int Nbcolonne = 20;

string Matrice[Nbligne][Nbcolonne];

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

	for (int x = 0; x < Nbligne; x++)
	{
		for (int y = 0; y < Nbcolonne; y++)
		{
		
			string ligne;
			while (getline(fichier, ligne, '#'))
			{
				Matrice[y][x] = ligne;
			}	
		}
	}

	fichier.close();

	for (int x = 0; x < Nbligne; x++)
	{
		for (int y = 0; y < Nbcolonne; y++)
		{
			cout << Matrice[y][x];
		}
	}

	}
	else  // sinon
		cout << "Impossible d'ouvrir le fichier !" << endl;

}
