#pragma once

#include "grille.h"
#include <chrono>
#include "GL/glut.h"


class cases :
	public grille
{
public:
	cases();
	~cases();

	int valPlanete = 0;
	int nbPlanete = 0;
	GLuint m_texturePlanete;

	static void dessinerSoleil(int);
	void dessinerPlanete();
	void dessinerTrouNoir();
	void dessinerFleches();
	void dessinerTeleporteur();


};

extern cases Case;