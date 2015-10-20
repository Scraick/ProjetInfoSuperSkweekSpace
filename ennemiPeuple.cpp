#include "ennemiPeuple.h"

ennemiPeuple::ennemiPeuple(int x, int y) : ennemi()
{
	m_x = x;
	m_y = y;
}

void ennemiPeuple::nombre()
{
}

double ennemiPeuple::distance()
{
	// Initialisation des valeurs de distance
	int val = 0;
	int valTemp = 100000;

	// Boucle pour la recherche des planétes
	for (int i = 0; i < NB_LIGNES; i++)
	{
		for (int j = 0; j < NB_COLONNES; j++)
		{
			if ((Matrice[i][j] == '2') && (planete == 4))
			{
				val = sqrt((positionX() - i) * (positionX() - i) + (positionY() - j) * (positionY() - j)); // Calcul de la distance entre le vaisseau et la planéte

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

//void ennemiPeuple::deplacement() 	// Déplacement vers la planéte la plus proche
//{
//	double mini;
//	int x, y;
//
//	mini = distance(t[0], t[1]);
//
//	for (int i = 0; i < 20; i++)
//	{
//		for (int j = 0; j < 20; j++)
//
//			if (mini > distance(t[i], t[j]))
//			{
//				mini = distance(t[i], t[j]);
//				x = i;
//				y = j;
//			}
//	}
//}

void ennemiPeuple::changerCase()
{
}