#include "bishop.h"
#include <cstdlib>


Bishop::Bishop(bool isWhite) : Piece(isWhite, 'B') {}
		
bool Bishop::isValidMove(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY)
{
	return abs(endY - startY) == abs(endX - startX);
}