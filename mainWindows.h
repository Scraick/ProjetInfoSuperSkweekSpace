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
	enum TypeCase
	{
		CASE_VIDE,		
		CASE_TROUNOIR,		
		CASE_PLANETE,
		CASE_SOLEIL,
		CASE_TP,
		CASE_FLECHE

	};


	mainWindows();
	~mainWindows();

	vector <GLuint>	texture;
	grille grilleTest;
	vector <cases> m_cases;
	vector <cases> m_casesActives;

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