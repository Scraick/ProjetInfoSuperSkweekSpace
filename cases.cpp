#include "cases.h"

cases Case;


cases::cases()
{
}


cases::~cases()
{
}

void cases::dessinerSoleil(int h)
{
	h = 200;
	int index;
	static int cpt = 0;
	cpt++;
	
	if (cpt == 1)
		index = 0;
	if (cpt == 2)
		index = 1;
	if (cpt == 3)
	{
		index = 2;
		cpt = 0;
	}

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, index);
	glBegin(GL_QUADS);
	glColor3d(1.0, 1.0, 1.0);
	glTexCoord2d(0.0f, 1.0f); glVertex2d(0, 0);
	glTexCoord2d(1.0f, 1.0f); glVertex2d(0 + 1, 0);
	glTexCoord2d(1.0f, 0.0f); glVertex2d(0 + 1, 0 + 1);
	glTexCoord2d(0.0f, 0.0f); glVertex2d(0, 0 + 1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
	glutTimerFunc(h, cases::dessinerSoleil, 0);
	
}

void cases::dessinerPlanete()
{

	if (valPlanete == 0)
	{
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D, m_texturePlanete);
		glBegin(GL_QUADS);
		glColor3d(1.0, 1.0, 1.0);
		glTexCoord2d(0.0f, 1.0f); glVertex2d(0, 0);
		glTexCoord2d(1.0f, 1.0f); glVertex2d(0 + 1, 0);
		glTexCoord2d(1.0f, 0.0f); glVertex2d(0 + 1, 0 + 1);
		glTexCoord2d(0.0f, 0.0f); glVertex2d(0, 0 + 1);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}


}

void cases::dessinerTrouNoir()
{

}

void cases::dessinerFleches()
{

}

void cases::dessinerTeleporteur()
{

}
