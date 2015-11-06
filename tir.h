#ifndef TIR_H
#define TIR_H

#include "grille.h"

class tir
{
public:
	tir();
	~tir();

	void shoot(int orientation);

	double bulletX();
	double bulletY();
	bool bulletActif();
	void setX(double x);
	void setY(double y);
	void setActif(bool a);

private:
	double m_bulletX;
	double m_bulletY;
	double m_speed = 0;
	int m_orientation;
	bool m_actif = false;
	int pt1, pt2, pt3, pt4;
};
extern tir bullet;
#endif