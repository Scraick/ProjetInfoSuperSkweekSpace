#ifndef MAINWINDOWS_H
#define MAINWINDOWS_H
#include <vector>
#include <string>
#include "GL/glut.h"
#include "SOIL/SOIL.h"
#include "grille.h"
#include "ennemi.h"
#include "player.h"

using namespace std;


class mainWindows
{
public:
	
	mainWindows();
	~mainWindows();

	vector <GLuint>	texture;
	vector <cases> m_cases; //Vecteur de cases, qui est rempli avec toutes les textures

	void init(int x, int y);
	void afficherTexture(double, double, double, double, const GLuint &);
	int LoadGLTextures(string);
	void dessinerNiveau();
	void dessinerJoueur();
	static void affichage();
	static void callback_affichage(int);
	static void redim(int x, int y);
	void loadtexture();

	static void clavier(int key, int x, int y);
	
};

extern mainWindows fenetre;

extern mainWindows mainWindow;

#endif

