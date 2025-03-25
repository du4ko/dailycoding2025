#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece 
{
	public:
		Queen(bool isWhite);
		bool isValidMove(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY) override;
};


#endif