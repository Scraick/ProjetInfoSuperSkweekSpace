#include "ennemiPeuple.h"

ennemiPeuple cargo01(25, 25);

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

void ennemiPeuple::deplacementEP(int h) 	// Déplacement vers la planète la plus proche
{
	h = 4000;

	cargo01.cptDeplacementRalenti++;
	
	if (cargo01.cptDeplacementRalenti == 250)
	{
		grilleJeu.distancePlanetes();
	
			// Si il a trouvé des planètes et que le booléen random est à faux, alors il se déplace vers les planètes

			if (grilleJeu.val_Y < cargo01.m_y) //Position Y plus basse
			{
				if (grilleJeu.val_X == cargo01.m_x) // et position X égale
				{
					cargo01.depHaut(); //Va vers le haut
				}
				else // si la position X n'est pas égale
				{
					if (grilleJeu.val_X > cargo01.m_x) // si elle est plus grande
					{
						cargo01.depDroit();// va vers la droite
					}
					else if (grilleJeu.val_X < cargo01.m_x) // si elle est plus petite 
					{
						cargo01.depGauche(); //Va vers la gauche
					}
				}
			}
			else if (grilleJeu.val_Y > cargo01.m_y)// Si la position Y est plus haute
			{
				if (grilleJeu.val_X == cargo01.m_x) // et position X égale
				{
					cargo01.depBas(); // Va vers le bas
				}
				else // si la position X n'est pas égale
				{
					if (grilleJeu.val_X > cargo01.m_x) // si elle est plus grande
					{
						cargo01.depDroit(); // va vers la droite
					}
					else if (grilleJeu.val_X < cargo01.m_x) // si elle est plus petite 
					{
						cargo01.depGauche(); //Va vers la gauche
					}
				}
			}
		
		cargo01.cptDeplacementRalenti = 0;
	}

	cargo01.changerCase();

	glutTimerFunc(h, cargo01.deplacementEP, 0);
}


void ennemiPeuple::depGauche() //Déplacement gauche
{
	valDep = 1;
	m_x --;
}

void ennemiPeuple::depDroit() //Déplacement droit
{
	valDep = 3;
	m_x ++;
}

void ennemiPeuple::depHaut() //Déplacement haut
{
	valDep = 0;
	m_y --;
}

void ennemiPeuple::depBas() //Déplacement bas
{
	valDep = 2;
	m_y ++;
}

void ennemiPeuple::changerCase()
{
	//Si la case détruite est bleue
	if (fenetre.bleu[cargo01.m_y][cargo01.m_x] == fenetre.texture[21])
	{
		if (fenetre.nbrPlaneteDetruite > 3)
		{
			grilleJeu.declencherBalayage = true; //Nouvelle recherche de planète
		}

		fenetre.bleu[cargo01.m_y][cargo01.m_x] = fenetre.texture[18]; //On change la texture en texture de base
		fenetre.nbrPlaneteDetruite--; //Nombre de planetes détruites est decrementé
		fenetre.scoreJoueur -= 50; //Score du joueur baissé de 50

		cout << "planète détruites : " << fenetre.nbrPlaneteDetruite << " " << "scoreJoueur : " << fenetre.scoreJoueur << endl;
	}

	//Si la case détruite est jaune
	if (fenetre.jaune[cargo01.m_y][cargo01.m_x] == fenetre.texture[22])
	{
		if (fenetre.nbrPlaneteDetruite > 3)
		{
			grilleJeu.declencherBalayage = true; //Nouvelle recherche de planète
		}

		fenetre.jaune[cargo01.m_y][cargo01.m_x] = fenetre.texture[19]; //On change la texture en texture de base
		fenetre.nbrPlaneteDetruite--; //Nombre de planetes détruites est decrementé
		fenetre.scoreJoueur -= 50; //Score du joueur baissé de 50

		cout << "planète détruites : " << fenetre.nbrPlaneteDetruite << " " << "scoreJoueur : " << fenetre.scoreJoueur << endl;
	}

	//Si la case détruite est rose
	if (fenetre.rose[cargo01.m_y][cargo01.m_x] == fenetre.texture[23])
	{
		if (fenetre.nbrPlaneteDetruite > 3)
		{
			grilleJeu.declencherBalayage = true; //Nouvelle recherche de planète
		}

		fenetre.rose[cargo01.m_y][cargo01.m_x] = fenetre.texture[20]; //On change la texture en texture de base
		fenetre.nbrPlaneteDetruite--; //Nombre de planetes détruites est decrementé
		fenetre.scoreJoueur -= 50; //Score du joueur baissé de 50

		cout << "planète détruites : " << fenetre.nbrPlaneteDetruite << " " << "scoreJoueur : " << fenetre.scoreJoueur << endl;
	}
}

