#include "piece.h"


Piece::Piece(bool isWhite, char Type) : isWhite(isWhite), Type(Type) {}

bool Piece::getColor() const {
	return isWhite;
};

char Piece::getType() const {
	return Type;
};