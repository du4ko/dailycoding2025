#include "knight.h"
#include <cstdlib>

Knight::Knight(bool isWhite) : Piece(isWhite, 'N') {}

bool Knight::isValidMove(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY)
{
	//using absolute to cover the negative if the knight is black
	int dx = abs(endX - startX);
	int dy = abs(endY - startY);
		
	return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}