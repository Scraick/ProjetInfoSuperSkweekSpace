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

	vector <cases> m_cases; //Vecteur de cases, qui est rempli avec toutes les textures
	cases casePlanetes; //Cases des planetes accesible depuis la grille pour le changement de texture
	cases planeteBleue, planeteJaune, planeteRose;

	void init(int x, int y);
	void afficherTexture(double, double, double, double, const GLuint &);
	void afficherTextureSoleil(double, double, double, double, const GLuint &);
	int LoadGLTextures(string);
	int tmp_x = 0, tmp_y = 0;
	int scoreJoueur = 0;

	vector <GLuint>	texture;
	GLuint bleu[60][32];
	GLuint jaune[60][32];
	GLuint rose[60][32];

	void dessinerNiveau();
	void dessinerJoueur();
	void dessinerPlanete();

	void planeteBleuDetruite();
	void planeteJauneDetruite();
	void planeteRoseDetruite();

	static void affichage();
	static void callback_affichage(int);
	void translationCam();

	static void redim(int x, int y);
	void loadtexture();

	void imageFond();
	
	static void clavier(int key, int x, int y);
	static void clavierUp(int key, int x, int y);
	
	int img_X = 0;
	int img_Y = 0;
};

extern mainWindows fenetre;
extern mainWindows mainWindow;
#endif

