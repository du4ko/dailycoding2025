#include "../headers/player.h"


Player::Player(char set_color) : color(set_color) {}

char Player::getPlayerColor()
{
	return color;
}


Player::~Player() {}