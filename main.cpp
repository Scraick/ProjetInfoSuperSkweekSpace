#include <vector>
#include "GL/glut.h"
#include "SOIL/SOIL.h"
#include "grille.h"
#include <string>

using namespace std;

grille grilleTest;

vector <GLuint>	texture;
GLuint m_instru;

void dessinerNiveau();
void affichage();
void redimmensionner();


int LoadGLTextures(string name) // Load Bitmaps And Convert To Textures
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

void affichage()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	dessinerNiveau();

	glFlush();
}

void redimmensionner(int x, int y)
{
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (double)20, (double)20, 0.0);

}

void dessinerNiveau()
{
	grilleTest.dessinerNiveauBas(); //remplissage de la matrice avec les valeurs

	for (int i = 0; i < 20; i++) // remplissage de la matrice avec les textures
	{
		for (int j = 0; j < 20; j++)
		{
			glEnable(GL_TEXTURE_2D);

			switch (Matrice[i][j])
			{
			case '0': // Sol
				glBegin(GL_QUADS);
				glColor3d(0.0, 0.0, 0.0);
				break;

			case '1': // Trou Noir
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0);
				break;

			case '2': // Planetes
				glBegin(GL_QUADS);
				glColor3d(0.3, 0.0, 0.4);
				break;

			case '3': // Soleil
				glBegin(GL_QUADS);
				glColor3d(0.0, 0.6, 0.6);
				break;

			case '4': // Teleporteur
				glBegin(GL_QUADS);
				glColor3d(0.5, 0.5, 0.5);
				break;

			case '5': // Cases flechées
				glBegin(GL_QUADS);
				glColor3d(0.3, 0.3, 0.0);
				break;

			}

			glTexCoord2d(0.0f, 1.0f); glVertex2d(i, j);
			glTexCoord2d(1.0f, 1.0f); glVertex2d(i + 1, j);
			glTexCoord2d(1.0f, 0.0f); glVertex2d(i + 1, j + 1);
			glTexCoord2d(0.0f, 0.0f); glVertex2d(i, j + 1);
			glEnd();
			glDisable(GL_TEXTURE_2D);
		}
	}
}

int main()
{
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(1000,1000);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutCreateWindow("Super Skweek");

	glutDisplayFunc(affichage);
	glutReshapeFunc(redimmensionner);

	glutMainLoop();

	return 0;
}