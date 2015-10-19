#include "grille.h"

const int Nbligne = 20;
const int Nbcolonne = 20;

char Matrice[Nbligne][Nbcolonne];

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

	for (int y = 0; y < Nbligne +1; y++)
	{
		for (int x = 0; x < Nbcolonne -1; x++)
		{
			char caractere;
			fichier.get(caractere);
			Matrice[x][y] = caractere;
		}
	}

	fichier.close();

	for (int y = 0; y < Nbligne; y++)
	{
		for (int x = 0; x < Nbcolonne; x++)
		{
			cout << Matrice[x][y];
		}
	}

	}
	else  // sinon
		cout << "Impossible d'ouvrir le fichier !" << endl;

}
