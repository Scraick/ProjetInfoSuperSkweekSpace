#include "mainWindows.h"

mainWindows fenetre;

vector <GLuint>	texture;
GLuint bleu[60][32];
GLuint jaune[60][32];
GLuint rose[60][32];

GLuint saveM1[60][32];
GLuint saveM2[60][32];

void dessinerTir(int);

mainWindows::mainWindows()
{
}

mainWindows::~mainWindows()
{
}

int mainWindows::LoadGLTextures(string name) // Load Bitmaps And Convert To Textures
{
	
	GLuint essai = SOIL_load_OGL_texture
		(
			name.c_str(),
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
			);

	texture.push_back(essai);

	if (texture.at(texture.size() - 1) == 0)
		return false;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return true;                                        // Return Success
}

void mainWindows::loadtexture()
{
	LoadGLTextures("textures/Sol.png");						// Sol				0

	LoadGLTextures("textures/murTrouNoir.png");				// Murs				1
	LoadGLTextures("textures/murTrouNoir02.png");			// Murs	2			2
	LoadGLTextures("textures/murTrouNoir03.png");			// Murs	3			3
	LoadGLTextures("textures/murTrouNoir04.png");			// Murs	4			4

	LoadGLTextures("textures/Soleil02.png");				// Soleil			5
	LoadGLTextures("textures/Soleil.png");					// Soleil	2		6
	LoadGLTextures("textures/Soleil03.png");				// Soleil	3		7

	LoadGLTextures("textures/Teleport.png");				// Tp				8

	LoadGLTextures("textures/ventSolaire.png");				// Flèches			9

	LoadGLTextures("textures/playerHaut.png");				// playerHaut		10
	LoadGLTextures("textures/playerGauche.png");			// playerGauche		11
	LoadGLTextures("textures/playerBas.png");				// playerBas		12
	LoadGLTextures("textures/playerDroite.png");			// playerDroite		13

	LoadGLTextures("textures/ventSolaire02.png");			// Flèches			14
	LoadGLTextures("textures/ventSolaire03.png");			// Flèches			15
	LoadGLTextures("textures/ventSolaire04.png");			// Flèches			16
	LoadGLTextures("textures/ventSolaire05.png");			// Flèches			17

	LoadGLTextures("textures/PlaneteBleue.png");			// PlanèteBleue		18
	LoadGLTextures("textures/PlaneteJaune.png");			// PlanèteJaune		19
	LoadGLTextures("textures/PlaneteRose.png");				// PlanèteRose		20
	LoadGLTextures("textures/PlaneteBleueDetruite.png");	// PlanèteBleueD	21
	LoadGLTextures("textures/PlaneteJauneDetruite.png");	// PlanèteJauneD	22
	LoadGLTextures("textures/PlaneteRoseDetruite.png");		// PlanèteRoseD		23

	LoadGLTextures("textures/NuageGalaxie.jpg");			// galaxie			24

	LoadGLTextures("textures/CargoHaut.png");				// ennemiPeuple		25
	LoadGLTextures("textures/CargoGauche.png");				// ennemiPeuple		26
	LoadGLTextures("textures/CargoBas.png");				// ennemiPeuple		27
	LoadGLTextures("textures/CargoDroite.png");				// ennemiPeuple		28

	LoadGLTextures("textures/Teleport02.png");				// teleport			29
	LoadGLTextures("textures/Teleport03.png");				// teleport			30
	LoadGLTextures("textures/Teleport04.png");				// teleport			31

	LoadGLTextures("textures/tir.png");						// Tir du joueur	32

	cases caseSoleil; // Creation de la case Soleil, qui contient les frames d'animation
	caseSoleil.m_id = '3';
	caseSoleil.sub_id = '0';
	caseSoleil.ajouterFrame(texture[5]);
	caseSoleil.ajouterFrame(texture[6]);
	caseSoleil.ajouterFrame(texture[7]);

	cases caseTrouNoir; // Creation de la case Trou Noir, qui contient les frames d'animation
	caseTrouNoir.m_id = '1';
	caseTrouNoir.sub_id = '0';
	caseTrouNoir.ajouterFrame(texture[1]);
	caseTrouNoir.ajouterFrame(texture[2]);
	caseTrouNoir.ajouterFrame(texture[3]);
	caseTrouNoir.ajouterFrame(texture[4]);

	cases caseVent; // Creation de la case Vent Solaire, qui contient les frames d'animation
	caseVent.m_id = '5';
	caseVent.sub_id = '0';
	caseVent.ajouterFrame(texture[9]);
	caseVent.ajouterFrame(texture[14]);
	caseVent.ajouterFrame(texture[15]);
	caseVent.ajouterFrame(texture[16]);
	caseVent.ajouterFrame(texture[17]);

	cases caseTeleport;
	caseTeleport.m_id = '4';
	caseTeleport.sub_id = '0';
	caseTeleport.ajouterFrame(texture[8]);
	caseTeleport.ajouterFrame(texture[29]);
	caseTeleport.ajouterFrame(texture[30]);
	caseTeleport.ajouterFrame(texture[31]);

	//Plusieurs numéros pour le moment, car l'attribution automatique ne fonctionne pas
	planeteBleue.m_id = '2';
	planeteJaune.m_id = '6';
	planeteRose.m_id = '7';

	//Puis remplissage de m_cases avec les autres textures non animées
	m_cases.push_back(cases(texture[0], '0', '0'));
	m_cases.push_back(caseTrouNoir);
	m_cases.push_back(cases(texture[0], '2', '0'));
	m_cases.push_back(caseSoleil);
	m_cases.push_back(caseTeleport);
	m_cases.push_back(caseVent);
	m_cases.push_back(cases(texture[0], '6', '0'));
	m_cases.push_back(cases(texture[0], '7', '0'));
	m_cases.push_back(cases(texture[0], '8', '0'));
}

void mainWindows::init(int x, int y)
{
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(x, y);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutCreateWindow("Super Skweek");

	loadtexture(); //Load des textures dans les vecteurs correspondants


	grilleJeu.dessinerNiveauBas(m_cases); //remplissage de la matrice avec les valeurs
	
	glutDisplayFunc(affichage);
	glutReshapeFunc(redim);

	cargo01.setX(55), cargo01.setY(29), cargo01.setVal(0), cargo01.setNumero(1), cargo01.setNbrPV(3);
	cargo02.setX(56), cargo02.setY(29), cargo02.setVal(0), cargo02.setNumero(2), cargo02.setNbrPV(3);
	cargo03.setX(57), cargo03.setY(29), cargo03.setVal(0), cargo03.setNumero(3), cargo03.setNbrPV(3);

	saveM1[60][32] = { texture[0] };
	saveM2[60][32] = { texture[0] };

	// Initialisation de la musique
	FMOD_SYSTEM *system;
	FMOD_SOUND *musique;
	FMOD_RESULT resultat;
	FMOD_System_Create(&system);
	FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, 0);
	resultat = FMOD_System_CreateSound(system, "sounds/Main_Theme.mp3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &musique);
	sons.music(system, musique, resultat);

	glutTimerFunc(16, callback_affichage, 0);
	glutMainLoop();

	sons.stop( system, musique, resultat);
}

void mainWindows::afficherTexture(double x, double y, double largeur, double hauteur, const GLuint &texture)
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
		glTexCoord2d(0, 1); glVertex2d(x, y);
		glTexCoord2d(1, 1); glVertex2d(x + largeur, y);
		glTexCoord2d(1, 0); glVertex2d(x + largeur, y + hauteur);
	glTexCoord2d(0, 0); glVertex2d(x, y + hauteur);
	glEnd();
	glDisable(GL_TEXTURE_2D);

}

void mainWindows::imageFond()
{
	int largeur = 60;
	int hauteur = 32;

	//grilleJeu.parallaxeFond(img_X, img_Y);

	//affichage différent, pour avoir une taille supérieure à 1 sur 1
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, texture[24]);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 1); glVertex2d(img_X, img_Y);
	glTexCoord2d(1, 1); glVertex2d(img_X + largeur, img_Y);
	glTexCoord2d(1, 0); glVertex2d(img_X + largeur, img_Y + hauteur);
	glTexCoord2d(0, 0); glVertex2d(img_X, img_Y + hauteur);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void mainWindows::dessinerNiveau()
{

	if (fenetre.niveauBas == true)
	{

	for (int i = 0; i < NB_LIGNES; i++) //Parcours de la matrice de cases et affichage des textures
		{
			for (int j = 0; j < NB_COLONNES; j++)
			{
				// Appel de la fonction textureAnime, qui permet de faire l'animation
				// Si il n'y a qu'un texture dans une case, il n'ya a pas d'animation
				// Ajout d'une condition pour que les soleils prennent quatres case
				if (grilleJeu.Matrice[i][j].m_id == '3')
				{
					afficherTexture(j, i, 2, 2, grilleJeu.Matrice[i][j].textureAnime());
				}
				else
				{
					afficherTexture(j, i, 1, 1, grilleJeu.Matrice[i][j].textureAnime());
				}
			}
		}

	if (fenetre.dessinerUneFois == true)
	{
		grilleJeu.dessinerNiveauBas(m_cases);

		fenetre.remplirPlanetes = true;
		fenetre.dessinerUneFois = false;

		cargo01.setX(55), cargo01.setY(29);
		cargo02.setX(56), cargo02.setY(29);
		cargo03.setX(57), cargo03.setY(29);

		grilleJeu.balayageDeLaMatrice = true;
		grilleJeu.balayageDeLaMatrice02 = true;
		grilleJeu.balayageDeLaMatrice03 = true;

		fenetre.nbrPlaneteDetruite = 0;
	}
	else
	{
		if (cptTP > 0)
		fenetre.remplirPlanetes = false;
	}

	fenetre.dessinerPlanete();

	}
	else
	{
	
		for (int i = 0; i < NB_LIGNES; i++) //Parcours de la matrice de cases et affichage des textures
		{
			for (int j = 0; j < NB_COLONNES; j++)
			{
				// Appel de la fonction textureAnime, qui permet de faire l'animation
				// Si il n'y a qu'un texture dans une case, il n'ya a pas d'animation
				// Ajout d'une condition pour que les soleils prennent quatres case
				if (grilleJeu.Matrice[i][j].m_id == '3')
				{
					afficherTexture(j, i, 2, 2, grilleJeu.Matrice[i][j].textureAnime());
				}
				else
				{
					afficherTexture(j, i, 1, 1, grilleJeu.Matrice[i][j].textureAnime());
				}
			}
		}

		if (fenetre.dessinerUneFois == false)
		{
			grilleJeu.dessinerNiveauHaut(m_cases);

			cptTP++;
			fenetre.remplirPlanetes = true;
			fenetre.dessinerUneFois = true;

			cargo01.setX(55), cargo01.setY(29);
			cargo02.setX(56), cargo02.setY(29);
			cargo03.setX(57), cargo03.setY(29);

			grilleJeu.balayageDeLaMatrice = true;
			grilleJeu.balayageDeLaMatrice02 = true;
			grilleJeu.balayageDeLaMatrice03 = true;

			fenetre.nbrPlaneteDetruite = 0;
		}
		else
		{
			fenetre.remplirPlanetes = false;
		}

		fenetre.dessinerPlanete();

	}
}

void mainWindows::dessinerEnnemiPeuple(ennemi vaisseauCargo)
{
		switch (vaisseauCargo.valDep)
		{
		case 0:
			afficherTexture(vaisseauCargo.positionX(), vaisseauCargo.positionY(), 1, 1, texture[25]);
			break;

		case 1:
			afficherTexture(vaisseauCargo.positionX(), vaisseauCargo.positionY() ,1, 1, texture[28]);
			break;

		case 2:
			afficherTexture(vaisseauCargo.positionX(), vaisseauCargo.positionY(), 1, 1, texture[27]);
			break;

		case 3:
			afficherTexture(vaisseauCargo.positionX(), vaisseauCargo.positionY(), 1, 1, texture[26]);
			break;
		}
}

void mainWindows::dessinerPlanete()
{

	for (int i = 0; i < NB_LIGNES; i++) //Parcours de la matrice et remplissage des textures de planètes
	{
		for (int j = 0; j < NB_COLONNES; j++)
		{
			if (grilleJeu.Matrice[i][j].m_id == '2')
			{
				if (fenetre.remplirPlanetes == true)
				{
					bleu[i][j] = texture[18]; 
					//bleu[i][j] = texture[21]; // test ennemiPeuple

					if (saveM1[i][j] == texture[21])
					{
						bleu[i][j] = texture[21];
						fenetre.nbrPlaneteDetruite++;
					}

					if (saveM2[i][j] == texture[21])
					{
						bleu[i][j] = texture[21];
						fenetre.nbrPlaneteDetruite++;
					}
				}

				afficherTexture(j, i, 1, 1, bleu[i][j]);
			}

			if (grilleJeu.Matrice[i][j].m_id == '6')
			{
				if (fenetre.remplirPlanetes == true)
				{
					jaune[i][j] = texture[19];
					//jaune[i][j] = texture[22]; // test ennemiPeuple

					if (saveM1[i][j] == texture[22])
					{
						jaune[i][j] = texture[22];
						fenetre.nbrPlaneteDetruite++;
					}

					if (saveM2[i][j] == texture[22])
					{
						jaune[i][j] = texture[22];
						fenetre.nbrPlaneteDetruite++;
					}
				}

				afficherTexture(j, i, 1, 1, jaune[i][j]);
			}

			if (grilleJeu.Matrice[i][j].m_id == '7')
			{

				if (fenetre.remplirPlanetes == true)
				{
					rose[i][j] = texture[20];
					//rose[i][j] = texture[23]; // test ennemiPeuple

					if (saveM1[i][j] == texture[23])
					{
						rose[i][j] = texture[23];
						fenetre.nbrPlaneteDetruite++;
					}

					if (saveM2[i][j] == texture[23])
					{
						rose[i][j] = texture[23];
						fenetre.nbrPlaneteDetruite++;
					}
				}

				afficherTexture(j, i, 1, 1, rose[i][j]);
			}
		}
	}
}

void mainWindows::dessinerJoueur()
{
	switch (joueur.valDep)
	{
	case 0: // Haut
		afficherTexture(joueur.positionX(), joueur.positionY(), 1.25, 1.25, texture[10]);
		break;
	case 1: // Gauche
		afficherTexture(joueur.positionX(), joueur.positionY(), 1.25, 1.25, texture[11]);
		break;
	case 2: // Bas
		afficherTexture(joueur.positionX(), joueur.positionY(), 1.25, 1.25, texture[12]);
		break;
	case 3: // Droite
		afficherTexture(joueur.positionX(), joueur.positionY(), 1.25, 1.25, texture[13]);
		break;
	}

	fenetre.remplirPlanetes = false;
}

void dessinerTir(int)
{
	bullet.shoot();
	glutTimerFunc(6400, dessinerTir, 0);
}

void mainWindows::dessinerTirs()
{
	fenetre.afficherTexture(bullet.bulletX(), bullet.bulletY(), 1, 1, fenetre.texture[32]);
}

void mainWindows::planeteBleuDetruite()
{
	tmp_x = joueur.positionX();
	tmp_y = joueur.positionY();

	if (bleu[tmp_y][tmp_x] == texture[18])
	{
		bleu[tmp_y][tmp_x] = texture[21];
		scoreJoueur += 100;
		nbrPlaneteDetruite += 1;
		cout << "planetes detruites = " << nbrPlaneteDetruite << endl;

		if (fenetre.niveauBas == true)
		{
			saveM1[tmp_y][tmp_x] = texture[21];
		}
		else
		{
			saveM2[tmp_y][tmp_x] = texture[21];
		}

	}	
}

void mainWindows::planeteJauneDetruite()
{
	tmp_x = joueur.positionX();
	tmp_y = joueur.positionY();

	if (jaune[tmp_y][tmp_x] == texture[19])
	{
		jaune[tmp_y][tmp_x] = texture[22];
		scoreJoueur += 100;
		nbrPlaneteDetruite += 1;
		cout << "planetes detruites = " << nbrPlaneteDetruite << endl;

		if (fenetre.niveauBas == true)
		{
			saveM1[tmp_y][tmp_x] = texture[22];
		}
		else
		{
			saveM2[tmp_y][tmp_x] = texture[22];
		}
	}
}

void mainWindows::planeteRoseDetruite()
{
	tmp_x = joueur.positionX();
	tmp_y = joueur.positionY();

	if (rose[tmp_y][tmp_x] == texture[20])
	{
		rose[tmp_y][tmp_x] = texture[23];
		scoreJoueur += 100;
		nbrPlaneteDetruite += 1;
		cout << "planetes detruites = " << nbrPlaneteDetruite << endl;

		if (fenetre.niveauBas == true)
		{
			saveM1[tmp_y][tmp_x] = texture[23];
		}
		else
		{
			saveM2[tmp_y][tmp_x] = texture[23];
		}
	}
}

void mainWindows::clavier(int key, int x, int y)
{
	if (!bullet.bulletActif())
	{
		bullet.setOrientation(joueur.valDep);
	}

	switch (key)
	{
	case GLUT_KEY_F1:
		exit(0);
		break;

	case GLUT_KEY_UP:
		grilleJeu.colisionHaut();
		joueur.valDep = 0;
		break;

	case GLUT_KEY_DOWN:
		grilleJeu.colisionBas();
		joueur.valDep = 2;
		break;

	case GLUT_KEY_LEFT:
		grilleJeu.colisionGauche();
		joueur.valDep = 1;
		break;

	case GLUT_KEY_RIGHT:
		grilleJeu.colisionDroite();
		joueur.valDep = 3;
		break;

	case GLUT_KEY_END:
		if (!bullet.bulletActif())
		{
			bullet.setX(joueur.positionX());
			bullet.setY(joueur.positionY());
			bullet.setActif(true);
			bullet.shoot();
		}
		else
		break;
	}
}

void mainWindows::clavierUp(int key, int x, int y)
{
	//if (key == GLUT_KEY_UP)
	//{
	//	joueur.velocityHaut();
	//}

	//if (key == GLUT_KEY_DOWN)
	//{
	//	joueur.velocityBas();
	//}

	//if (key == GLUT_KEY_LEFT)
	//{
	//	joueur.velocityGauche();
	//}

	//if (key == GLUT_KEY_RIGHT)
	//{
	//	joueur.velocityDroit();
	//}
	if (key == GLUT_KEY_END)
	{
		//tir = false;
	}
}

void mainWindows::redim(int x, int y)
{
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glScalef(2, 2, 0);
	gluOrtho2D(0.0, (double)NB_COLONNES, (double)NB_LIGNES, 0.0);
}

void mainWindows::translationCam()
{
	double i = 29;
	double j = 15.5;

	glLoadIdentity();

	//Coin haut/gauche
	if (joueur.positionX() < 15)
	{
		i = 14 + joueur.positionX();
	}
	if (joueur.positionY() < 8.5)
	{
		j = 7 + joueur.positionY();
	}

	//Coin bas/droite
	if (joueur.positionX() > 43)
	{
		i = joueur.positionX() - 14;
	}
	if (joueur.positionY() > 22.5)
	{
		j = joueur.positionY() - 7;
	}

	//Centre de l'écran
	glTranslatef(-joueur.positionX() + i, -joueur.positionY() + j, 0);

	glutSwapBuffers();
}

void mainWindows::affichage()
{
	glClearColor(0.0, 0.0, 0.0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	fenetre.imageFond();
	fenetre.dessinerNiveau();

	fenetre.translationCam();
	grilleJeu.verifPosition();
	fenetre.dessinerJoueur();


	if (bullet.bulletActif() == true)
	{
		fenetre.dessinerTirs();
		glutTimerFunc(64, dessinerTir, 0);
	}


	if (fenetre.nbrPlaneteDetruite > 4)
	{	
		// Si le nombre de planètes détruites est supérieur à 4, l'ennemi apparait et bouge vers elles
		if (grilleJeu.declencherBalayage == true)
		{
			grilleJeu.balayageDeLaMatrice = true;
			grilleJeu.declencherBalayage = false;
		}

		cargo01.deplacementEP(cargo01);
		fenetre.dessinerEnnemiPeuple(cargo01);
	}

	if (fenetre.nbrPlaneteDetruite > 9)
	{
		// Si le nombre de planètes détruites est supérieur à 9, l'ennemi 2 apparait et bouge vers elles
		if (grilleJeu.declencherBalayage02 == true)
		{
			grilleJeu.balayageDeLaMatrice02 = true;
			grilleJeu.declencherBalayage02 = false;
		}

		cargo02.deplacementEP(cargo02);
		fenetre.dessinerEnnemiPeuple(cargo02);
	}

	if (fenetre.nbrPlaneteDetruite > 14)
	{
		// Si le nombre de planètes détruites est supérieur à 14, l'ennemi 3 apparait et bouge vers elles
		if (grilleJeu.declencherBalayage03 == true)
		{
			grilleJeu.balayageDeLaMatrice03 = true;
			grilleJeu.declencherBalayage03 = false;
		}

		cargo03.deplacementEP(cargo03);
		fenetre.dessinerEnnemiPeuple(cargo03);
	}


	glutSpecialFunc(fenetre.clavier); // Appuie des touches du clavier
	glutSpecialUpFunc(fenetre.clavierUp); // Touche du clavier relaché
	//	glutFullScreen();

	glFlush();
	glutTimerFunc(16, callback_affichage, 0);
}

void mainWindows::callback_affichage(int) // utiliser pour atteindre la fonction affichage
{
	affichage();
}