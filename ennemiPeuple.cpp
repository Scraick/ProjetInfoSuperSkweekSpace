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

	if (cptDeplacementRalenti == 200)
	{
		//cout << "verification distance cargo01" << endl;
		grilleJeu.distancePlanetes(vaisseauCargo.m_x, vaisseauCargo.m_y);

			// Si il a trouvé des planètes et que le booléen random est à faux, alors il se déplace vers les planètes

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

			//cout << "Valeur vaisseauCargo : " << vaisseauCargo.valDep << endl;
			//cout << "Valeur Cargo01 : " << cargo01.valDep << endl;

			cout << "position vaisseauCargo : " << vaisseauCargo.positionX() << " " << vaisseauCargo.positionY() << endl;
			cout << "position Cargo01 : " << cargo01.positionX() << " " << cargo01.positionY() << endl;
	}
	
	grilleJeu.changerCase(vaisseauCargo);

}

double ennemiPeuple::positionX()
{
	return m_x;
}

double ennemiPeuple::positionY()
{
	return m_y;
}
