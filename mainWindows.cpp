#include "mainWindows.h"


mainWindows mainWindow;

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
	LoadGLTextures("textures/NOIRTest.png");	// Sol			0
	LoadGLTextures("textures/NOIRTest.png");	// Murs			1
	LoadGLTextures("textures/NOIRTest.png");	// Planètes		2
	LoadGLTextures("textures/Soleil02.png");	// Soleil		3
	LoadGLTextures("textures/Soleil.png");		// Soleil	2	4
	LoadGLTextures("textures/Soleil03.png");	// Soleil	3	5
	LoadGLTextures("textures/NOIRTest.png");	// Tp			6
	LoadGLTextures("textures/NOIRTest.png");	// Flèches		7


	cases caseSoleil; // Creation de la case Soleil, qui contient les frames d'animation
	caseSoleil.ajouterFrame(texture[3]);
	caseSoleil.ajouterFrame(texture[4]);
	caseSoleil.ajouterFrame(texture[5]);

	//Puis remplissage de m_cases avec les autres textures non animèes
	m_cases.push_back(cases(texture[0]));
	m_cases.push_back(cases(texture[1]));
	m_cases.push_back(cases(texture[2]));
	m_cases.push_back(caseSoleil);
	m_cases.push_back(cases(texture[6]));
	m_cases.push_back(cases(texture[7]));
}

void mainWindows::init(int x, int y)
{
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(x, y);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutCreateWindow("Super Skweek");

	loadtexture(); //Moad des textures dans les vecteurs correspondants
	grilleTest.dessinerNiveauBas(m_cases); //remplissage de la matrice avec les valeurs
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

void  mainWindows::dessinerNiveau()
{
	int index;
	GLuint tmpTexture;

	for (int i = 0; i < NB_LIGNES; i++) //Parcours de la matrice de cases et affichage des textures
	{
		for (int j = 0; j < NB_COLONNES; j++)
		{
			//Appel de la fonction textureAnime, qui permet de faire l'animation
			//Si il n'y a qu'un texture dans une case, il n'ya a pas d'animation
			afficherTexture(i, j, 1, 1, grilleTest.Matrice[i][j].textureAnime()); 
		}
	}
}

void  mainWindows::affichage()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	mainWindow.dessinerNiveau();

	glFlush();
	glutTimerFunc(80, callback_affichage, 0);
}

void mainWindows::callback_affichage(int) // utiliser pour atteindre la fonction affichage
{
	affichage();
}

void mainWindows::redim(int x, int y)
{
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (double)NB_LIGNES, (double)NB_COLONNES, 0.0);
}
