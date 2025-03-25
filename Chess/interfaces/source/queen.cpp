#include "queen.h"
#include <cstdlib>

Queen::Queen(bool isWhite) : Piece(isWhite, 'Q') {}
bool Queen::isValidMove(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY)
{
	return (abs(endY - startY) == abs(endX - startX)) ||
		((startX == endX) || (startY == endY));
}