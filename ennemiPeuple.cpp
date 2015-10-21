#include "ennemiPeuple.h"

ennemiPeuple::ennemiPeuple()
{
}


int ennemiPeuple::positionX()
{
	return m_x;
}

int ennemiPeuple::positionY()
{
	return m_y;
}

//void ennemiPeuple::deplacementEP() 	// Déplacement vers la planéte la plus proche
//{
//	double mini;
//	int x, y;
//
//	mini = distance(t[0], t[1]);
//
//	for (int i = 0; i < 20; i++)
//	{
//		for (int j = 0; j < 20; j++)
//
//			if (mini > distance(t[i], t[j]))
//			{
//				mini = distance(t[i], t[j]);
//				x = i;
//				y = j;
//			}
//	}
//}
