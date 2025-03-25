#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece{
	public:
		Pawn(bool isWhite);
		bool isValidMove(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY) override;
};

#endif