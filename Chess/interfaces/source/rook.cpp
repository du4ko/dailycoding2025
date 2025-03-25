#include "rook.h"

Rook::Rook(bool isWhite) : Piece(isWhite, 'R') {}
bool Rook::isValidMove(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY)
{
	return (startX == endX) || (startY == endY);
}
