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
	LoadGLTextures("textures/Soleil02.png");	// Sol			0
	LoadGLTextures("textures/Soleil02.png");	// Murs			1
	LoadGLTextures("textures/Soleil02.png");	// Planètes		2
	LoadGLTextures("textures/Soleil02.png");	// Soleil		3
	LoadGLTextures("textures/Soleil02.png");	// Tp			4
	LoadGLTextures("textures/Soleil02.png");	// Flèches		5
}

void mainWindows::init(int x, int y)
{
	grilleTest.dessinerNiveauBas(); //remplissage de la matrice avec les valeurs

	glutInitWindowPosition(10, 10);
	glutInitWindowSize(x, y);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutCreateWindow("Super Skweek");

	loadtexture();
	glutDisplayFunc(affichage);
	glutReshapeFunc(redim);

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

	for (int i = 0; i < NB_LIGNES; i++) // remplissage de la matrice avec les textures
	{
		for (int j = 0; j < NB_COLONNES; j++)
		{
			index = grilleTest.Matrice[i][j] - '0';
			afficherTexture(i, j, 1, 1, texture[index]);
		}
	}
}

void  mainWindows::affichage()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	mainWindow.dessinerNiveau();

	glFlush();
}

void mainWindows::redim(int x, int y)
{
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (double)NB_LIGNES, (double)NB_COLONNES, 0.0);
}
