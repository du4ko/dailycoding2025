#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece 
{
	public:
		Bishop(bool isWhite);
		bool isValidMove(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY) override;
};

#endif