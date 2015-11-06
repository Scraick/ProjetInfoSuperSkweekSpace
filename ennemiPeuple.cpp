#include "ennemiPeuple.h"

ennemiPeuple cargo01(25, 25), cargo02(26, 26), cargo03(25, 26);
int cptDeplacementRalenti = 0;

ennemiPeuple::ennemiPeuple(double x, double y)
{
	m_x = x;
	m_y = y;
}

void ennemiPeuple::nombre()
{
}

double ennemiPeuple::positionX()
{
	return m_x;
}

double ennemiPeuple::positionY()
{
	return m_y;
}

void ennemiPeuple::deplacementEP(int h, ennemiPeuple &vaisseauCargo) 	// D�placement vers la plan�te la plus proche
{
	h = grilleJeu.speedEnnemiP;

	cptDeplacementRalenti++;

	if (cptDeplacementRalenti == 100)
	{
		//cout << "verification distance cargo01" << endl;

		grilleJeu.distancePlanetes(vaisseauCargo.m_x, vaisseauCargo.m_y);
	
			// Si il a trouv� des plan�tes et que le bool�en random est � faux, alors il se d�place vers les plan�tes

			if (grilleJeu.val_Y < vaisseauCargo.m_y) //Position Y plus basse
			{
				if (grilleJeu.val_X == vaisseauCargo.m_x) // et position X �gale
				{
					vaisseauCargo.valDep = 0;
					vaisseauCargo.m_y--;; //Va vers le haut
				}
				else // si la position X n'est pas �gale
				{
					if (grilleJeu.val_X > vaisseauCargo.m_x) // si elle est plus grande
					{
						vaisseauCargo.valDep = 3;
						vaisseauCargo.m_x++;// va vers la droite
					}
					else if (grilleJeu.val_X < vaisseauCargo.m_x) // si elle est plus petite 
					{
						vaisseauCargo.valDep = 1;
						vaisseauCargo.m_x--; //Va vers la gauche
					}
				}
			}
			else if (grilleJeu.val_Y > vaisseauCargo.m_y)// Si la position Y est plus haute
			{
				if (grilleJeu.val_X == vaisseauCargo.m_x) // et position X �gale
				{
					vaisseauCargo.valDep = 2;
					vaisseauCargo.m_y++; // Va vers le bas
				}
				else // si la position X n'est pas �gale
				{
					if (grilleJeu.val_X > vaisseauCargo.m_x) // si elle est plus grande
					{
						vaisseauCargo.valDep = 3;
						vaisseauCargo.m_x++; // va vers la droite
					}
					else if (grilleJeu.val_X < vaisseauCargo.m_x) // si elle est plus petite 
					{
						vaisseauCargo.valDep = 1;
						vaisseauCargo.m_x--; //Va vers la gauche
					}
				}
			}
		
			cptDeplacementRalenti = 0;
	}

	vaisseauCargo.changerCase(vaisseauCargo);
}


void ennemiPeuple::depGauche() //D�placement gauche
{
	valDep = 1;
	m_x --;
}

void ennemiPeuple::depDroit() //D�placement droit
{
	valDep = 3;
	m_x ++;
}

void ennemiPeuple::depHaut() //D�placement haut
{
	valDep = 0;
	m_y --;
}

void ennemiPeuple::depBas() //D�placement bas
{
	valDep = 2;
	m_y ++;
}

void ennemiPeuple::changerCase(ennemiPeuple vaisseauCargo)
{
	//Si la case d�truite est bleue
	if (fenetre.bleu[vaisseauCargo.m_y][vaisseauCargo.m_x] == fenetre.texture[21])
	{
		if (fenetre.nbrPlaneteDetruite > 5)
		{
			grilleJeu.declencherBalayage = true; //Nouvelle recherche de plan�te
		}

		fenetre.bleu[vaisseauCargo.m_y][vaisseauCargo.m_x] = fenetre.texture[18]; //On change la texture en texture de base
		fenetre.scoreJoueur -= 50; //Score du joueur baiss� de 50

		cout << "plan�te d�truites : " << fenetre.nbrPlaneteDetruite << " " << "scoreJoueur : " << fenetre.scoreJoueur << endl;
	}


	//Si la case d�truite est jaune
	if (fenetre.jaune[vaisseauCargo.m_y][vaisseauCargo.m_x] == fenetre.texture[22])
	{
		if (fenetre.nbrPlaneteDetruite > 5)
		{
			grilleJeu.declencherBalayage = true; //Nouvelle recherche de plan�te
		}

		fenetre.jaune[vaisseauCargo.m_y][vaisseauCargo.m_x] = fenetre.texture[19]; //On change la texture en texture de base
		fenetre.scoreJoueur -= 50; //Score du joueur baiss� de 50

		cout << "plan�te d�truites : " << fenetre.nbrPlaneteDetruite << " " << "scoreJoueur : " << fenetre.scoreJoueur << endl;
	}


	//Si la case d�truite est rose
	if (fenetre.rose[vaisseauCargo.m_y][vaisseauCargo.m_x] == fenetre.texture[23])
	{
		if (fenetre.nbrPlaneteDetruite > 5)
		{
			grilleJeu.declencherBalayage = true; //Nouvelle recherche de plan�te
		}

		fenetre.rose[vaisseauCargo.m_y][vaisseauCargo.m_x] = fenetre.texture[20]; //On change la texture en texture de base
		fenetre.scoreJoueur -= 50; //Score du joueur baiss� de 50

		cout << "plan�te d�truites : " << fenetre.nbrPlaneteDetruite << " " << "scoreJoueur : " << fenetre.scoreJoueur << endl;
	}
}

