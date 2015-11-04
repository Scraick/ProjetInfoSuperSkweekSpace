#include "mainWindows.h"

mainWindows fenetre;
vector <GLuint>	texture;
GLuint bleu[60][32];
GLuint jaune[60][32];
GLuint rose[60][32];

void dessinerTir(int);
bool tire = false;

mainWindows::mainWindows()
{
}

mainWindows::~mainWindows()
{
}

int  mainWindows::LoadGLTextures(string name) // Load Bitmaps And Convert To Textures
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
	LoadGLTextures("textures/ventSolaire.png");				// Fl�ches			9
	LoadGLTextures("textures/playerHaut.png");				// playerHaut		10
	LoadGLTextures("textures/playerGauche.png");			// playerGauche		11
	LoadGLTextures("textures/playerBas.png");				// playerBas		12
	LoadGLTextures("textures/playerDroite.png");			// playerDroite		13
	LoadGLTextures("textures/ventSolaire02.png");			// Fl�ches			14
	LoadGLTextures("textures/ventSolaire03.png");			// Fl�ches			15
	LoadGLTextures("textures/ventSolaire04.png");			// Fl�ches			16
	LoadGLTextures("textures/ventSolaire05.png");			// Fl�ches			17
	LoadGLTextures("textures/PlaneteBleue.png");			// Plan�teBleue		18
	LoadGLTextures("textures/PlaneteJaune.png");			// Plan�teJaune		19
	LoadGLTextures("textures/PlaneteRose.png");				// Plan�teRose		20
	LoadGLTextures("textures/PlaneteBleueDetruite.png");	// Plan�teBleueD	21
	LoadGLTextures("textures/PlaneteJauneDetruite.png");	// Plan�teJauneD	22
	LoadGLTextures("textures/PlaneteRoseDetruite.png");		// Plan�teRoseD		23
	LoadGLTextures("textures/tir.png");						// Tir du joueur	24



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

	//Plusieurs num�ros pour le moment, car l'attribution automatique ne fonctionne pas
	planeteBleue.m_id = '2';
	planeteJaune.m_id = '6';
	planeteRose.m_id = '7';

	//Puis remplissage de m_cases avec les autres textures non anim�es
	m_cases.push_back(cases(texture[0], '0', '0'));
	m_cases.push_back(caseTrouNoir);
	m_cases.push_back(cases(texture[0], '2', '0'));
	m_cases.push_back(caseSoleil);
	m_cases.push_back(cases(texture[8], '4', '0'));
	m_cases.push_back(caseVent);
	m_cases.push_back(cases(texture[0], '6', '0'));
	m_cases.push_back(cases(texture[0], '7', '0'));
	
	
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

	glutTimerFunc(16, callback_affichage, 0);

	glutMainLoop();
}

void mainWindows::afficherTexture(double x, double y, double largeur, double hauteur, const GLuint &texture)
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glColor3d(1.0, 1.0, 1.0);
	glTexCoord2d(0, hauteur); glVertex2d(x, y);
	glTexCoord2d(largeur, hauteur); glVertex2d(x + largeur, y);
	glTexCoord2d(largeur, 0); glVertex2d(x + largeur, y + hauteur);
	glTexCoord2d(0, 0); glVertex2d(x, y + hauteur);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void  mainWindows::affichage()
{
	glClearColor(0.0, 0.0157, 0.0313, 1);  
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	fenetre.translationCam();

	fenetre.dessinerNiveau();
	fenetre.dessinerPlanete();

	grilleJeu.verifPosition();
	fenetre.dessinerJoueur();

	fenetre.afficherTexture(bullet.bulletX(), bullet.bulletY(), 5, 1, texture[24]);


	glutTimerFunc(16, dessinerTir, 0);

	glutSpecialFunc(fenetre.clavier); // Appuie des touches du clavier
	glutSpecialUpFunc(fenetre.clavierUp); // Touche du clavier relach�
	//glutFullScreen();

	glFlush();
	glutTimerFunc(16, callback_affichage, 0);
}

void  mainWindows::dessinerNiveau()
{
	for (int i = 0; i < NB_LIGNES ; i++) //Parcours de la matrice de cases et affichage des textures
	{
		for (int j = 0; j < NB_COLONNES ; j++)
		{
			// Appel de la fonction textureAnime, qui permet de faire l'animation
			// Si il n'y a qu'un texture dans une case, il n'ya a pas d'animation
			afficherTexture(j, i, 1, 1, grilleJeu.Matrice[i][j].textureAnime());
		}
	}

}

void mainWindows::dessinerJoueur()
{
	switch (joueur.valDep)
	{
	case 0:
		afficherTexture(joueur.positionX(), joueur.positionY(), 1, 1, texture[10]);
		break;

	case 1:
		afficherTexture(joueur.positionX(), joueur.positionY(), 1, 1, texture[11]);
		break;

	case 2:
		afficherTexture(joueur.positionX(), joueur.positionY(), 1, 1, texture[12]);
		break;

	case 3:
		afficherTexture(joueur.positionX(), joueur.positionY(), 1, 1, texture[13]);
		break;
	}
}

void mainWindows::dessinerPlanete()
{

	for (int i = 0; i < NB_LIGNES; i++) //Parcours de la matrice et remplissage des textures de plan�tes
	{
		for (int j = 0; j < NB_COLONNES; j++)
		{
			if (grilleJeu.Matrice[i][j].m_id == '2')
			{
				if ((joueur.positionX() == 1) && (joueur.positionY() == 1))
				{
					bleu[i][j] = texture[18];
				}

				afficherTexture(j, i, 1, 1, bleu[i][j]);
			}

			if (grilleJeu.Matrice[i][j].m_id == '6')
			{
				if ((joueur.positionX() == 1) && (joueur.positionY() == 1))
				{
					jaune[i][j] = texture[19];
				}

				afficherTexture(j, i, 1, 1, jaune[i][j]);
			}

			if (grilleJeu.Matrice[i][j].m_id == '7')
			{
				if ((joueur.positionX() == 1) && (joueur.positionY() == 1))
				{
					rose[i][j] = texture[20];
				}

				afficherTexture(j, i, 1, 1, rose[i][j]);
			}
		}
	}

}

void dessinerTir(int)
{
	bullet.shoot(joueur.valDep);
	glutTimerFunc(5000, dessinerTir, 0);
}

void mainWindows::planeteBleuDetruite()
{
	tmp_x = joueur.positionX();
	tmp_y = joueur.positionY();

	if (bleu[tmp_y][tmp_x] == texture[18])
	{
		bleu[tmp_y][tmp_x] = texture[21];
		scoreJoueur += 100;
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
	}
}

void mainWindows::clavier(int key, int x, int y)
{
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
		bool tire = true;
		bullet.setX(joueur.positionX());
		bullet.setY(joueur.positionY());
		bullet.shoot(joueur.valDep);
		cout << bullet.bulletX() << endl;
		cout << bullet.bulletY() << endl;
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
	glScalef(2, 2, 0);
	gluOrtho2D(0.0, (double)NB_COLONNES, (double)NB_LIGNES, 0.0);
}

void mainWindows::translationCam()
{
	double i = 29;
	double j = 15.5;

	glLoadIdentity();

	//Coin haut/gauche
	if (joueur.positionX() < 14)
	{
		i = 15 + joueur.positionX();
	}
	if (joueur.positionY() < 7.5)
	{
		j = 8 + joueur.positionY();
	}

	//Coin bas/droite
	if (joueur.positionX() > 44)
	{
		i = joueur.positionX() - 15;
	}
	if (joueur.positionY() > 23.5)
	{
		j = joueur.positionY() - 8;
	}

	//Centre de l'�cran
	glTranslatef(-joueur.positionX() + i, -joueur.positionY() + j, 0);

	glutSwapBuffers();
}

void mainWindows::callback_affichage(int) // utiliser pour atteindre la fonction affichage
{
	affichage();
}