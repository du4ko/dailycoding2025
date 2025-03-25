#include "king.h"
#include <cstdlib>


King::King(bool isWhite) : Piece(isWhite, 'K') {}
bool King::isValidMove(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY)
{
	return abs(startX - endX) == 1 || abs(startY - endY) == 1 ||
		 (abs(startX - endX) == 1 && abs(startY - endY) == 1);
}