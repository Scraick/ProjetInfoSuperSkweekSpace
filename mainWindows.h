#pragma once
#include <vector>
#include <string>
#include "GL/glut.h"
#include "SOIL/SOIL.h"
#include "grille.h"

using namespace std;


class mainWindows
{
public:
	mainWindows();
	~mainWindows();

	vector <GLuint>	texture;
	grille grilleTest;

	void init(int x, int y);
	void afficherTexture(double, double, double, double, const GLuint &);
	int LoadGLTextures(string);
	void dessinerNiveau();
	static void affichage();
	static void redim(int x, int y);
	void loadtexture();
};

extern mainWindows mainWindow;