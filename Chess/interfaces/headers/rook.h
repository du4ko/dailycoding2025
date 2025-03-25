#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
	public:
		Rook(bool isWhite);
		bool isValidMove(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY) override;
};

#endif