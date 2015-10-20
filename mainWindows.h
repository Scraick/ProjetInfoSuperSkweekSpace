#pragma once
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
	grille grilleTest;
	vector <cases> m_cases; //Vecteur de cases, qui est rempli avec toutes les textures
	//vector <cases> m_casesActives;

	void init(int x, int y);
	void afficherTexture(double, double, double, double, const GLuint &);
	int LoadGLTextures(string);
	void dessinerNiveau();
	static void affichage();
	static void callback_affichage(int);
	static void redim(int x, int y);
	void loadtexture();
};

extern mainWindows mainWindow;