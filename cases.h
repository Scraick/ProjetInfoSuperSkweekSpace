#pragma once

#include <vector>
#include <chrono>
#include "GL/glut.h"


class cases
{
public:
	cases();
	cases(GLuint texture);
	~cases();
	std::vector<GLuint> m_textures;
	int frame;
	int ralentissementAnim;

	virtual GLuint textureAnime();
	void ajouterFrame(GLuint texture);
};

extern cases Case;