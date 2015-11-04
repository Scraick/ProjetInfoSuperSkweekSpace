#include "cases.h"

cases Case;

cases::cases()
{
	frame = -1; //d�but de frame a -1, pour que la frame '0' se joue en premi�re, et non la frame '1'
	ralentissementAnim = 25;
}

cases::~cases()
{
}

cases::cases(GLuint texture, char id, char id2)
{
	frame = -1;
	m_textures.push_back(texture);
	m_id = id;
	sub_id = id2;
}


GLuint cases::textureAnime()
{

	frame = (frame + 1) % (m_textures.size() * ralentissementAnim); //Incr�mentation de la frame, puis retour au d�but lorsque le nombre max de frame est atteint
	return m_textures[(frame / ralentissementAnim)];

}

GLuint cases::textureAnimePassage()
{
	if (frame < (3 * ralentissementAnim))
	{
		frame++;
	}
	
	return m_textures[(frame / ralentissementAnim)];
}

void cases::ajouterFrame(GLuint texture) //Fonction pour remplir une case de plusieurs frames, comme dans la case soleil, afin de les animer
{
	m_textures.push_back(texture);
}



