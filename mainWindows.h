#ifndef MAINWINDOWS_H
#define MAINWINDOWS_H
#include <vector>
#include <string>
#include "GL/glut.h"
#include "SOIL/SOIL.h"
#include "grille.h"
#include "ennemi.h"
#include "ennemiPeuple.h"
#include "player.h"
#include "tir.h"
#include "sound.h"

using namespace std;

class mainWindows 
{
public:
	mainWindows();
	~mainWindows();

	vector <GLuint>	texture;
	vector <cases> m_cases; //Vecteur de cases, qui est rempli avec toutes les textures
	cases casePlanetes; //Cases des planetes accesible depuis la grille pour le changement de texture
	cases planeteBleue, planeteJaune, planeteRose;
	GLuint bleu[60][32];
	GLuint jaune[60][32];
	GLuint rose[60][32];

	void init(int x, int y);
	void afficherTexture(double, double, double, double, const GLuint &);
	int LoadGLTextures(string);
	int tmp_x = 0, tmp_y = 0;
	int scoreJoueur = 0;
	int nbrPlaneteDetruite = 0; // test ennemis = 18

	void dessinerNiveau();
	void dessinerJoueur();
	void dessinerEnnemiPeuple(ennemi);
	void dessinerPlanete();

	void dessinerTirs();

	void planeteBleuDetruite();
	void planeteJauneDetruite();
	void planeteRoseDetruite();

	static void affichage();
	static void callback_affichage(int);
	static void redim(int x, int y);
	bool niveauBas = true;
	bool dessinerUneFois = false;
	bool remplirPlanetes = true;
	int cptTP = 0;

	void translationCam();
	void loadtexture();
	void imageFond();
	
	static void clavier(int key, int x, int y);
	static void clavierUp(int key, int x, int y);	

	int img_X = 0;
	int img_Y = 0;
};
extern mainWindows fenetre;
extern vector <GLuint> texture;
#endif

