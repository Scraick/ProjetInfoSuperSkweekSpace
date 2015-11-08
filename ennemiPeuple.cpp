#include "ennemiPeuple.h"

int cptDeplacementRalenti = 0;

ennemiPeuple::ennemiPeuple()
{
}

void ennemiPeuple::nombre()
{
}

void ennemi::deplacementEP(ennemi &vaisseauCargo) 	// Déplacement vers la planète la plus proche
{
	cptDeplacementRalenti++;

	if (cptDeplacementRalenti == 40)
	{
		if (vaisseauCargo.numeroEnnemi == 1)
		{
			grilleJeu.distancePlanetes(vaisseauCargo.m_x, vaisseauCargo.m_y);

			if (grilleJeu.val_Y < vaisseauCargo.m_y) //Position Y plus basse
			{
				if (grilleJeu.val_X == vaisseauCargo.m_x) // et position X égale
				{
					grilleJeu.depHaut(vaisseauCargo); //Va vers le haut
				}
				else // si la position X n'est pas égale
				{
					if (grilleJeu.val_X > vaisseauCargo.m_x) // si elle est plus grande
					{
						grilleJeu.depDroite(vaisseauCargo);// va vers la droite
					}
					else if (grilleJeu.val_X < vaisseauCargo.m_x) // si elle est plus petite 
					{
						grilleJeu.depGauche(vaisseauCargo); //Va vers la gauche
					}
				}
			}
			else if (grilleJeu.val_Y > vaisseauCargo.m_y)// Si la position Y est plus haute
			{
				if (grilleJeu.val_X == vaisseauCargo.m_x) // et position X égale
				{
					grilleJeu.depBas(vaisseauCargo); // Va vers le bas
				}
				else // si la position X n'est pas égale
				{
					if (grilleJeu.val_X > vaisseauCargo.m_x) // si elle est plus grande
					{
						grilleJeu.depDroite(vaisseauCargo); // va vers la droite
					}
					else if (grilleJeu.val_X < vaisseauCargo.m_x) // si elle est plus petite 
					{
						grilleJeu.depGauche(vaisseauCargo); //Va vers la gauche
					}
				}
			}
			else // si la position Y est égale
			{
				if (grilleJeu.val_X < vaisseauCargo.m_x) // Si la position X est plus petite
				{
					grilleJeu.depGauche(vaisseauCargo); // va vers la gauche
				}

				if (grilleJeu.val_X > vaisseauCargo.m_x) // Si la position X est plus grande
				{
					grilleJeu.depDroite(vaisseauCargo); // va vers la droite
				}
			}

			cptDeplacementRalenti = 0;
		}

		if (vaisseauCargo.numeroEnnemi == 2)
		{
			grilleJeu.distancePlanetes(vaisseauCargo.m_x, vaisseauCargo.m_y);

			if (grilleJeu.val_Y2 < vaisseauCargo.m_y) //Position Y plus basse
			{
				if (grilleJeu.val_X2 == vaisseauCargo.m_x) // et position X égale
				{
					grilleJeu.depHaut(vaisseauCargo); //Va vers le haut
				}
				else // si la position X n'est pas égale
				{
					if (grilleJeu.val_X2 > vaisseauCargo.m_x) // si elle est plus grande
					{
						grilleJeu.depDroite(vaisseauCargo);// va vers la droite
					}
					else if (grilleJeu.val_X2 < vaisseauCargo.m_x) // si elle est plus petite 
					{
						grilleJeu.depGauche(vaisseauCargo); //Va vers la gauche
					}
				}
			}
			else if (grilleJeu.val_Y2 > vaisseauCargo.m_y)// Si la position Y est plus haute
			{
				if (grilleJeu.val_X2 == vaisseauCargo.m_x) // et position X égale
				{
					grilleJeu.depBas(vaisseauCargo); // Va vers le bas
				}
				else // si la position X n'est pas égale
				{
					if (grilleJeu.val_X2 > vaisseauCargo.m_x) // si elle est plus grande
					{
						grilleJeu.depDroite(vaisseauCargo); // va vers la droite
					}
					else if (grilleJeu.val_X2 < vaisseauCargo.m_x) // si elle est plus petite 
					{
						grilleJeu.depGauche(vaisseauCargo); //Va vers la gauche
					}
				}
			}
			else // si la position Y est égale
			{
				if (grilleJeu.val_X2 < vaisseauCargo.m_x) // Si la position X est plus petite
				{
					grilleJeu.depGauche(vaisseauCargo); // va vers la gauche
				}

				if (grilleJeu.val_X2 > vaisseauCargo.m_x) // Si la position X est plus grande
				{
					grilleJeu.depDroite(vaisseauCargo); // va vers la droite
				}
			}

			cptDeplacementRalenti = 0;
		}

		if (vaisseauCargo.numeroEnnemi == 3)
		{
			grilleJeu.distancePlanetes(vaisseauCargo.m_x, vaisseauCargo.m_y);

			if (grilleJeu.val_Y3 < vaisseauCargo.m_y) //Position Y plus basse
			{
				if (grilleJeu.val_X3 == vaisseauCargo.m_x) // et position X égale
				{
					grilleJeu.depHaut(vaisseauCargo); //Va vers le haut
				}
				else // si la position X n'est pas égale
				{
					if (grilleJeu.val_X3 > vaisseauCargo.m_x) // si elle est plus grande
					{
						grilleJeu.depDroite(vaisseauCargo);// va vers la droite
					}
					else if (grilleJeu.val_X3 < vaisseauCargo.m_x) // si elle est plus petite 
					{
						grilleJeu.depGauche(vaisseauCargo); //Va vers la gauche
					}
				}
			}
			else if (grilleJeu.val_Y3 > vaisseauCargo.m_y)// Si la position Y est plus haute
			{
				if (grilleJeu.val_X3 == vaisseauCargo.m_x) // et position X égale
				{
					grilleJeu.depBas(vaisseauCargo); // Va vers le bas
				}
				else // si la position X n'est pas égale
				{
					if (grilleJeu.val_X3 > vaisseauCargo.m_x) // si elle est plus grande
					{
						grilleJeu.depDroite(vaisseauCargo); // va vers la droite
					}
					else if (grilleJeu.val_X3 < vaisseauCargo.m_x) // si elle est plus petite 
					{
						grilleJeu.depGauche(vaisseauCargo); //Va vers la gauche
					}
				}
			}
			else // si la position Y est égale
			{
				if (grilleJeu.val_X3 < vaisseauCargo.m_x) // Si la position X est plus petite
				{
					grilleJeu.depGauche(vaisseauCargo); // va vers la gauche
				}

				if (grilleJeu.val_X3 > vaisseauCargo.m_x) // Si la position X est plus grande
				{
					grilleJeu.depDroite(vaisseauCargo); // va vers la droite
				}
			}

			cptDeplacementRalenti = 0;
		}

		cout << "position Cargo01 : " << cargo01.positionX() << " " << cargo01.positionY() << endl;
		cout << "position Cargo02 : " << cargo02.positionX() << " " << cargo02.positionY() << endl;
		cout << "position Cargo03 : " << cargo03.positionX() << " " << cargo03.positionY() << endl;
	}
	
	grilleJeu.changerCase();

}

double ennemiPeuple::positionX()
{
	return m_x;
}

double ennemiPeuple::positionY()
{
	return m_y;
}
