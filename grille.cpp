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
	ifstream fichier("Matrice01.txt", ios::in);  // on ouvre le fichier en lecture

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

void grille::dessinerNiveauHaut(vector<cases> C)
{
	ifstream fichier("Matrice02.txt", ios::in);  // on ouvre le fichier en lecture

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

double grille::distancePlanetes(double x, double y)
{
	// Initialisation des valeurs de distance
	

	if (balayageDeLaMatrice == true)
	{
		int val;
		int valTemp = 100000;

		// Boucle pour la recherche des plan�tes

		for (int i = 0; i < NB_LIGNES; i++)
		{
			for (int j = 0; j < NB_COLONNES; j++)
			{
				if ((Matrice[i][j].m_id == '2') && (fenetre.bleu[i][j] == fenetre.texture[21]))
				{
						val = sqrt((x - i) * (x - i) + (y - j) * (y - j)); // Calcul de la distance entre le vaisseau et la plan�te

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
		
		std::cout << "Planete � reparer : "<< val_X << " " << val_Y << endl;
		std::cout << "Recherche en cours" << endl;
	}

	if (balayageDeLaMatrice02 == true)
	{
		int val;
		int valTemp = 100000;
		// Boucle pour la recherche des plan�tes

		for (int i = 0; i < NB_LIGNES; i++)
		{
			for (int j = 0; j < NB_COLONNES; j++)
			{
				if ((Matrice[i][j].m_id == '6') && (fenetre.jaune[i][j] == fenetre.texture[22]))
				{
					val = sqrt((x - i) * (x - i) + (y - j) * (y - j)); // Calcul de la distance entre le vaisseau et la plan�te

					if (val < valTemp)
					{
						val_X2 = j;
						val_Y2 = i;
						balayageDeLaMatrice02 = false;
						valTemp = val; // Mise en place d'une valeur temp
						cout << "passage et changement des valeurs 02?" << endl;
					}
				}
			}
		}

		std::cout << "Planete � reparer : " << val_X2 << " " << val_Y2 << endl;
		std::cout << "Recherche en cours" << endl;
	}

	if (balayageDeLaMatrice03 == true)
	{
		int val;
		int valTemp = 100000;
		// Boucle pour la recherche des plan�tes

		for (int i = 0; i < NB_LIGNES; i++)
		{
			for (int j = 0; j < NB_COLONNES; j++)
			{
				if ((Matrice[i][j].m_id == '7') && (fenetre.rose[i][j] == fenetre.texture[23]))
				{
					val = sqrt((x - i) * (x - i) + (y - j) * (y - j)); // Calcul de la distance entre le vaisseau et la plan�te

					if (val < valTemp)
					{
						val_X3 = j;
						val_Y3 = i;
						balayageDeLaMatrice03 = false;
						valTemp = val; // Mise en place d'une valeur temp
						cout << "passage et changement des valeurs 03?" << endl;
					}
				}
			}
		}

		std::cout << "Planete � reparer : " << val_X3 << " " << val_Y3 << endl;
		std::cout << "Recherche en cours" << endl;

	}

	return 0;
}

void grille::respawnEnnemi()
{

}

void grille::speedEnnemis()
{
	speedEnnemiP = 3200;
}

void grille::colisionHaut()
{
	int	pt1 = round(joueur.positionX() - 0.2);
	int	pt2 = round(joueur.positionX() + 0.2);
	int	pt3 = round(joueur.positionY() - 0.2);
	int	pt4 = round(joueur.positionY() + 0.2);

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
	int pt3 = round(joueur.positionY() - 0.2);
	int pt4 = round(joueur.positionY() + 0.2);

	if (((grilleJeu.Matrice[pt4][(int)pt1].m_id != '1') && (grilleJeu.Matrice[pt4][(int)pt2].m_id != '1'))
		&& ((grilleJeu.Matrice[pt4][(int)pt1].m_id != '3') && (grilleJeu.Matrice[pt4][(int)pt2].m_id != '3'))
		&& ((grilleJeu.Matrice[pt4][(int)pt1].m_id != '8') && (grilleJeu.Matrice[pt4][(int)pt2].m_id != '8')))
	{
		joueur.depBas();
	}
}

void grille::colisionGauche()
{
	int pt1 = round(joueur.positionX() - 0.2);
	int pt2 = round(joueur.positionX() + 0.2);
	int pt3 = round(joueur.positionY() - 0.2);
	int pt4 = round(joueur.positionY() + 0.2);

	if (((grilleJeu.Matrice[(int)pt3][pt1].m_id != '1') && (grilleJeu.Matrice[pt4][(int)pt1].m_id != '1'))
		&& ((grilleJeu.Matrice[(int)pt3][pt1].m_id != '3') && (grilleJeu.Matrice[pt4][(int)pt1].m_id != '3'))
		&& ((grilleJeu.Matrice[(int)pt3][pt1].m_id != '8') && (grilleJeu.Matrice[pt4][(int)pt1].m_id != '8')))
	{
		joueur.depGauche();
	}
}

void grille::colisionDroite()
{
	int pt1 = round(joueur.positionX() - 0.2);
	int pt2 = round(joueur.positionX() + 0.2);
	int pt3 = round(joueur.positionY() - 0.2);
	int pt4 = round(joueur.positionY() + 0.2);


	if (((grilleJeu.Matrice[(int)pt3][pt2].m_id != '1') && (grilleJeu.Matrice[(int)pt4][pt2].m_id != '1'))
		&& ((grilleJeu.Matrice[(int)pt3][pt2].m_id != '3') && (grilleJeu.Matrice[(int)pt4][pt2].m_id != '3'))
		&& ((grilleJeu.Matrice[(int)pt3][pt2].m_id != '8') && (grilleJeu.Matrice[(int)pt4][pt2].m_id != '8')))
	{
		joueur.depDroit();
	}
}

void grille::colisionHautEP(ennemi &vaisseauCargo)
{
	/*int	pt1 = round(vaisseauCargo.positionX() - 0.4);
	int	pt2 = round(vaisseauCargo.positionX() + 0.4);
	int	pt3 = round(vaisseauCargo.positionY() - 0.4);
	int	pt4 = round(vaisseauCargo.positionY() + 0.4);

	if (((grilleJeu.Matrice[pt3][(int)pt1].m_id != '1') && (grilleJeu.Matrice[pt3][(int)pt2].m_id != '1'))
		&& ((grilleJeu.Matrice[pt3][(int)pt1].m_id != '3') && (grilleJeu.Matrice[pt3][(int)pt2].m_id != '3'))
		&& ((grilleJeu.Matrice[pt3][(int)pt1].m_id != '8') && (grilleJeu.Matrice[pt3][(int)pt2].m_id != '8')))
	{*/
		//depHaut();
		vaisseauCargo.setVal(0);
		vaisseauCargo.m_y--;
	/*}
	else
	{
		grilleJeu.colisionDroiteEP(vaisseauCargo);
	}*/
}

void grille::colisionBasEP(ennemi &vaisseauCargo)
{
	/*int pt1 = round(vaisseauCargo.positionX() - 0.4);
	int pt2 = round(vaisseauCargo.positionX() + 0.4);
	int pt3 = round(vaisseauCargo.positionY() - 0.4);
	int pt4 = round(vaisseauCargo.positionY() + 0.4);

	if (((grilleJeu.Matrice[pt4][(int)pt1].m_id != '1') && (grilleJeu.Matrice[pt4][(int)pt2].m_id != '1'))
		&& ((grilleJeu.Matrice[pt4][(int)pt1].m_id != '3') && (grilleJeu.Matrice[pt4][(int)pt2].m_id != '3'))
		&& ((grilleJeu.Matrice[pt4][(int)pt1].m_id != '8') && (grilleJeu.Matrice[pt4][(int)pt2].m_id != '8')))
	{*/
		//depBas();
		vaisseauCargo.setVal(2);
		vaisseauCargo.m_y++;
	/*}
	else
	{
		grilleJeu.colisionGaucheEP(vaisseauCargo);
	}*/
}

void grille::colisionGaucheEP(ennemi &vaisseauCargo)
{
	/*int pt1 = round(vaisseauCargo.positionX() - 0.4);
	int pt2 = round(vaisseauCargo.positionX() + 0.4);
	int pt3 = round(vaisseauCargo.positionY() - 0.4);
	int pt4 = round(vaisseauCargo.positionY() + 0.4);

	if (((grilleJeu.Matrice[(int)pt3][pt1].m_id != '1') && (grilleJeu.Matrice[pt4][(int)pt1].m_id != '1'))
		&& ((grilleJeu.Matrice[(int)pt3][pt1].m_id != '3') && (grilleJeu.Matrice[pt4][(int)pt1].m_id != '3'))
		&& ((grilleJeu.Matrice[(int)pt3][pt1].m_id != '8') && (grilleJeu.Matrice[pt4][(int)pt1].m_id != '8')))
	{*/
		vaisseauCargo.setVal(1);
		vaisseauCargo.m_x--;
	/*}
	else
	{
		grilleJeu.colisionHautEP(vaisseauCargo);
	}*/
}

void grille::colisionDroiteEP(ennemi &vaisseauCargo)
{
	/*int pt1 = round(vaisseauCargo.positionX() - 0.4);
	int pt2 = round(vaisseauCargo.positionX() + 0.4);
	int pt3 = round(vaisseauCargo.positionY() - 0.4);
	int pt4 = round(vaisseauCargo.positionY() + 0.4);

	if (((grilleJeu.Matrice[(int)pt3][pt2].m_id != '1') && (grilleJeu.Matrice[(int)pt4][pt2].m_id != '1'))
		&& ((grilleJeu.Matrice[(int)pt3][pt2].m_id != '3') && (grilleJeu.Matrice[(int)pt4][pt2].m_id != '3'))
		&& ((grilleJeu.Matrice[(int)pt3][pt2].m_id != '8') && (grilleJeu.Matrice[(int)pt4][pt2].m_id != '8')))
	{*/
		//depDroit();
		vaisseauCargo.setVal(3);
		vaisseauCargo.m_x++;
	/*}
	else
	{
		grilleJeu.colisionBasEP(vaisseauCargo);
	}*/
}

void grille::depGauche(ennemi &vaisseauCargo)
{
	vaisseauCargo.setVal(1);
	vaisseauCargo.m_x--;
	
}

void grille::depDroite(ennemi &vaisseauCargo)
{
	vaisseauCargo.setVal(3);
	vaisseauCargo.m_x++;
	
}

void grille::depHaut(ennemi &vaisseauCargo)
{
	vaisseauCargo.setVal(0);
	vaisseauCargo.m_y--;

}

void grille::depBas(ennemi &vaisseauCargo)
{
	vaisseauCargo.setVal(2);
	vaisseauCargo.m_y++;
	
}


void grille::changerCase()
{
	//Si la case d�truite est bleue
	if (fenetre.bleu[cargo01.positionY()][cargo01.positionX()] == fenetre.texture[21])
	{
		grilleJeu.balayageDeLaMatrice = true; //Nouvelle recherche de plan�te

		fenetre.bleu[cargo01.positionY()][cargo01.positionX()] = fenetre.texture[18]; //On change la texture en texture de base
		fenetre.scoreJoueur -= 50; //Score du joueur baiss� de 50
		fenetre.nbrPlaneteDetruite --;

		cout << "scoreJoueur : " << fenetre.scoreJoueur << endl;
	}


	//Si la case d�truite est jaune
	if (fenetre.jaune[cargo02.positionY()][cargo02.positionX()] == fenetre.texture[22])
	{
		grilleJeu.balayageDeLaMatrice02 = true;//Nouvelle recherche de plan�te

		fenetre.jaune[cargo02.positionY()][cargo02.positionX()] = fenetre.texture[19]; //On change la texture en texture de base
		fenetre.scoreJoueur -= 50; //Score du joueur baiss� de 50
		fenetre.nbrPlaneteDetruite--;

		cout << "scoreJoueur : " << fenetre.scoreJoueur << endl;
	}


	//Si la case d�truite est rose
	if (fenetre.rose[cargo03.positionY()][cargo03.positionX()] == fenetre.texture[23])
	{
		grilleJeu.balayageDeLaMatrice03 = true;//Nouvelle recherche de plan�te

		fenetre.rose[cargo03.positionY()][cargo03.positionX()] = fenetre.texture[20]; //On change la texture en texture de base
		fenetre.scoreJoueur -= 50; //Score du joueur baiss� de 50
		fenetre.nbrPlaneteDetruite--;

		cout << "scoreJoueur : " << fenetre.scoreJoueur << endl;
	}
}

double grille::parallaxeFond(double posX, double posY)
{
	fenetre.img_X = posX;
	fenetre.img_Y = posY;
	return posX, posY;
}

bool grille::verifPosition()
{
	int	pt1 = round(joueur.positionX());
	int	pt2 = round(joueur.positionX());
	int	pt3 = round(joueur.positionY());
	int	pt4 = round(joueur.positionY());

	int posX = joueur.positionX(), posY = joueur.positionY();

	if ((grilleJeu.Matrice[pt3][pt1].m_id == '2') && (grilleJeu.Matrice[pt3][pt2].m_id == '2')) // Case Planetes Bleues
	{
		fenetre.planeteBleuDetruite();
		return 0;
	}

	if ((grilleJeu.Matrice[pt3][pt1].m_id == '4') && (grilleJeu.Matrice[pt3][pt2].m_id == '4')) // Case Teleport
	{
		if (fenetre.niveauBas == true)
		{
			fenetre.niveauBas = false;
			cout << "check" << endl;
			return fenetre.niveauBas;

		}

		if (fenetre.niveauBas == false)
		{
			fenetre.niveauBas = true;
			cout << "check" << endl;
			return fenetre.niveauBas;

		}

	}

	if ((grilleJeu.Matrice[pt3][pt1].m_id == '5') && (grilleJeu.Matrice[pt3][pt2].m_id == '5')) // Case Fleches
	{
		glutTimerFunc(250, grilleJeu.callBackFleches, 0);
		return 0;
	}

	if ((grilleJeu.Matrice[pt3][pt1].m_id == '6') && (grilleJeu.Matrice[pt3][pt2].m_id == '6')) // Case Planetes Jaunes
	{
		fenetre.planeteJauneDetruite();
		return 0;
	}

	if ((grilleJeu.Matrice[pt3][pt1].m_id == '7') && (grilleJeu.Matrice[pt3][pt2].m_id == '7')) // Case Planetes Roses
	{
		fenetre.planeteRoseDetruite();
		return 0;
	}

	return 0;
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