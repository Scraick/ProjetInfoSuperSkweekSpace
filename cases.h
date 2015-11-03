#ifndef CASES_H
#define CASES_H
#include <vector>
#include <chrono>
#include "GL/glut.h"



class cases
{
public:
	cases();
	cases(GLuint texture, char id, char id2);
	~cases();

	std::vector<GLuint> m_textures;
	int frame; //Nombre de frame dans notre case animée
	int ralentissementAnim; //ralentissement de l'animation
	char m_id;
	char sub_id;

	virtual GLuint textureAnime(); //Fonction qui ajoute une frame a chaque rafraichissement, pour animer la case
	virtual GLuint textureAnimePassage(); // Fonction qui anime les planetes sur lesquelles le joueur passe
	void ajouterFrame(GLuint texture);

};

extern cases Case;

#endif
