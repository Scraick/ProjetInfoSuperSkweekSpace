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

double grille::distancePlanetes(double x, double y)
{
	// Initialisation des valeurs de distance
	int val ;
	int valTemp = 100000;

	if (balayageDeLaMatrice == true)
	{
		// Boucle pour la recherche des planètes

	for (int i = 0; i < NB_LIGNES; i++)
	{
		for (int j = 0; j < NB_COLONNES; j++)
		{
			if ((Matrice[i][j].m_id == '2') && (fenetre.bleu[i][j] == fenetre.texture[21])
					|| (Matrice[i][j].m_id == '6') && (fenetre.jaune[i][j] == fenetre.texture[22])
					|| (Matrice[i][j].m_id == '7') && (fenetre.rose[i][j] == fenetre.texture[23]))
			{
					val = sqrt((x - i) * (x - i) + (y - j) * (y - j)); // Calcul de la distance entre le vaisseau et la planète

				if (val < valTemp)
				{
						val_X = j;
						val_Y = i;
						balayageDeLaMatrice = false;
					valTemp = val; // Mise en place d'une valeur temp
				}
			}
		}
		}
		cout << "Recherche en cours" << endl;
	}

	return valTemp;
}


void grille::respawnEnnemi()
{

}

void grille::speedEnnemis()
{
	speedEnnemiP = 4000;
}

void grille::colisionHaut()
{
	int	pt1 = round(joueur.positionX() - 0.4);
	int	pt2 = round(joueur.positionX() + 0.4);
	int	pt3 = round(joueur.positionY() - 0.6);
	int	pt4 = round(joueur.positionY() + 0.4);

	if (((grilleJeu.Matrice[pt3][(int)pt1].m_id != '1') && (grilleJeu.Matrice[pt3][(int)pt2].m_id != '1'))
		&& ((grilleJeu.Matrice[pt3][(int)pt1].m_id != '3') && (grilleJeu.Matrice[pt3][(int)pt2].m_id != '3'))
		&& ((grilleJeu.Matrice[pt3][(int)pt1].m_id != '8') && (grilleJeu.Matrice[pt3][(int)pt2].m_id != '8')))
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

	if (((grilleJeu.Matrice[pt4][(int)pt1].m_id != '1') && (grilleJeu.Matrice[pt4][(int)pt2].m_id != '1'))
		&& ((grilleJeu.Matrice[pt4][(int)pt1].m_id != '3') && (grilleJeu.Matrice[pt4][(int)pt2].m_id != '3'))
		&& ((grilleJeu.Matrice[pt4][(int)pt1].m_id != '8') && (grilleJeu.Matrice[pt4][(int)pt2].m_id != '8')))
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

	if (((grilleJeu.Matrice[(int)pt3][pt1].m_id != '1') && (grilleJeu.Matrice[pt4][(int)pt1].m_id != '1'))
		&& ((grilleJeu.Matrice[(int)pt3][pt1].m_id != '3') && (grilleJeu.Matrice[pt4][(int)pt1].m_id != '3'))
		&& ((grilleJeu.Matrice[(int)pt3][pt1].m_id != '8') && (grilleJeu.Matrice[pt4][(int)pt1].m_id != '8')))
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


	if (((grilleJeu.Matrice[(int)pt3][pt2].m_id != '1') && (grilleJeu.Matrice[(int)pt4][pt2].m_id != '1'))
		&& ((grilleJeu.Matrice[(int)pt3][pt2].m_id != '3') && (grilleJeu.Matrice[(int)pt4][pt2].m_id != '3'))
		&& ((grilleJeu.Matrice[(int)pt3][pt2].m_id != '8') && (grilleJeu.Matrice[(int)pt4][pt2].m_id != '8')))
	{
		joueur.depDroit();
	}
}

double grille::parallaxeFond(double posX, double posY)
{
	fenetre.img_X = posX;
	fenetre.img_Y = posY;
	return posX, posY;
}

void grille::verifPosition()
{
	int	pt1 = round(joueur.positionX());
	int	pt2 = round(joueur.positionX());
	int	pt3 = round(joueur.positionY());
	int	pt4 = round(joueur.positionY());

	if ((grilleJeu.Matrice[pt3][pt1].m_id == '5') && (grilleJeu.Matrice[pt3][pt2].m_id == '5'))
	{
		glutTimerFunc(250, grilleJeu.callBackFleches, 0);
	}

	if ((grilleJeu.Matrice[pt3][pt1].m_id == '2') && (grilleJeu.Matrice[pt3][pt2].m_id == '2'))
	{
		fenetre.planeteBleuDetruite();
	}

	if ((grilleJeu.Matrice[pt3][pt1].m_id == '6') && (grilleJeu.Matrice[pt3][pt2].m_id == '6'))
	{
		fenetre.planeteJauneDetruite();
	}

	if ((grilleJeu.Matrice[pt3][pt1].m_id == '7') && (grilleJeu.Matrice[pt3][pt2].m_id == '7'))
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
		colisionHaut();
		break;

	case 1:
		colisionBas();
		break;

	case 2:
		colisionGauche();
		break;

	case 3:
		colisionDroite();
		break;
	}
}

void grille::callBackFleches(int call)
{
	grilleJeu.caseFleches();
}