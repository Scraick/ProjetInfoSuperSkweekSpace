#include "cases.h"

cases Case;


cases::cases()
{
	frame = -1;
	ralentissementAnim = 5;
}

cases::cases(GLuint texture)
{
	frame = -1;
	m_textures.push_back(texture);
}

cases::~cases()
{
}

GLuint cases::textureAnime()
{
	frame = (frame + 1) % (m_textures.size() * ralentissementAnim);
	return m_textures[(frame / ralentissementAnim)];
}

void cases::ajouterFrame(GLuint texture)
{
	m_textures.push_back(texture);
}
