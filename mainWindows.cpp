#include "mainWindows.h"

mainWindows fenetre;

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
	LoadGLTextures("textures/Sol.png");			// Sol			0
	LoadGLTextures("textures/murTrouNoir.png");	// Murs			1
	LoadGLTextures("textures/murTrouNoir02.png");	// 2
	LoadGLTextures("textures/murTrouNoir03.png");	// 3
	LoadGLTextures("textures/murTrouNoir04.png");	// 4
	LoadGLTextures("textures/NOIRTest.png");	// Planètes		5
	LoadGLTextures("textures/Soleil02.png");	// Soleil		6
	LoadGLTextures("textures/Soleil.png");		// Soleil	2	7
	LoadGLTextures("textures/Soleil03.png");	// Soleil	3	8
	LoadGLTextures("textures/Teleport.png");	// Tp			9
	LoadGLTextures("textures/ventSolaire.png");	// Flèches		10
	LoadGLTextures("textures/playerHaut.png");	// playerHaut   11
	LoadGLTextures("textures/playerGauche.png");// playerGauche	12
	LoadGLTextures("textures/playerBas.png");	// playerBas	13
	LoadGLTextures("textures/playerDroite.png");// playerDroite	14
	LoadGLTextures("textures/ventSolaire02.png");	// Flèches		15
	LoadGLTextures("textures/ventSolaire03.png");	// Flèches		16
	LoadGLTextures("textures/ventSolaire04.png");	// Flèches		17
	LoadGLTextures("textures/ventSolaire05.png");	// Flèches		18

	cases caseSoleil; // Creation de la case Soleil, qui contient les frames d'animation
	caseSoleil.m_id = '3';
	caseSoleil.ajouterFrame(texture[6]);
	caseSoleil.ajouterFrame(texture[7]);
	caseSoleil.ajouterFrame(texture[8]);

	cases caseTrouNoir;
	caseTrouNoir.m_id = '1';
	caseTrouNoir.ajouterFrame(texture[1]);
	caseTrouNoir.ajouterFrame(texture[2]);
	caseTrouNoir.ajouterFrame(texture[3]);
	caseTrouNoir.ajouterFrame(texture[4]);

	cases caseVent;
	caseVent.m_id = '5';
	caseVent.ajouterFrame(texture[10]);
	caseVent.ajouterFrame(texture[15]);
	caseVent.ajouterFrame(texture[16]);
	caseVent.ajouterFrame(texture[17]);
	caseVent.ajouterFrame(texture[18]);

	//Puis remplissage de m_cases avec les autres textures non animèes
	m_cases.push_back(cases(texture[0], '0'));
	m_cases.push_back(caseTrouNoir);
	m_cases.push_back(cases(texture[5], '2'));
	m_cases.push_back(caseSoleil);
	m_cases.push_back(cases(texture[9], '4'));
	m_cases.push_back(caseVent);

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

	
	joueur.translationCam();
	fenetre.dessinerNiveau();
	fenetre.dessinerJoueur();
	
	//glutFullScreen();

	glutSpecialFunc(fenetre.clavier); // Appuie des touches du clavier
	glutSpecialUpFunc(fenetre.clavierUp); // Touche du clavier relaché

	glFlush();
	glutTimerFunc(100, callback_affichage, 0);
}

void  mainWindows::dessinerNiveau()
{

	for (int i = 0; i < 32; i++) //Parcours de la matrice de cases et affichage des textures
	{
		for (int j = 0; j < 60; j++)
		{
			//Appel de la fonction textureAnime, qui permet de faire l'animation
			//Si il n'y a qu'un texture dans une case, il n'ya a pas d'animation
			afficherTexture(j, i, 1, 1, grilleJeu.Matrice[i][j].textureAnime());
		}
	}
}

void mainWindows::dessinerJoueur()
{
	switch (joueur.valDep)
	{
	case 0:
		afficherTexture(joueur.positionX(), joueur.positionY(), 1, 1, texture[11]);
		break;

	case 1:
		afficherTexture(joueur.positionX(), joueur.positionY(), 1, 1, texture[12]);
		break;

	case 2:
		afficherTexture(joueur.positionX(), joueur.positionY(), 1, 1, texture[13]);
		break;

	case 3:
		afficherTexture(joueur.positionX(), joueur.positionY(), 1, 1, texture[14]);
		break;
	}
}

void mainWindows::clavier(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_F1 :
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
	}
}

void mainWindows::clavierUp(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
		joueur.velocityHaut();
	}

	if (key == GLUT_KEY_DOWN)
	{
		joueur.velocityBas();
	}

	if (key == GLUT_KEY_LEFT)
	{
		joueur.velocityGauche();
	}

	if (key == GLUT_KEY_RIGHT)
	{
		joueur.velocityDroit();
	}
}

void mainWindows::redim(int x, int y)
{
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glScalef(2.5, 2.5, 0);
	gluOrtho2D(0.0, (double)60, (double)32, 0.0);
}

void mainWindows::callback_affichage(int) // utiliser pour atteindre la fonction affichage
{
	affichage();
}