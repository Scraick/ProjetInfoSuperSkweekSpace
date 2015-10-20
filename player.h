#ifndef PLAYER_H
#define PLAYER_H


class player
{
public:
	player(int x, int y);
	~player();

	int positionX();
	int positionY();

protected:
	int m_x, m_y;
	int m_nbVie;
};

#endif