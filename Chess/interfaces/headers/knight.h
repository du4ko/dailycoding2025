#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece
{
	public:
	Knight(bool isWhite);
	bool isValidMove(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY) override;
};

#endif