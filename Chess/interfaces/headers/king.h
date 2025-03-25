#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
	public:
		King(bool isWhite);
		bool isValidMove(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY) override;
};

#endif