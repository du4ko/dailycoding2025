#ifndef PLAYER_H
#define PLAYER_H


class Player
{
	private:
		char color;
	public:
		Player(char color);
		~Player();
		char getPlayerColor();
};

#endif