#ifndef PIECE_H  //Its good practise to add headguards to make sure we dont get the diamond problem
#define PIECE_H

#include <cstdint>

class Piece
{
	protected:
		bool isWhite; //true for white, false for black
		char Type; //the type of the piece (pawn , bishop and etc)
	public:
		Piece(bool isWhite, char Type);
		//Make sure the destructor is virtual as we inted to use polymorphism (virtual keyword make sure the compiler frees all memory upon destroing the object)
		virtual ~Piece() = default;
		//This is valid moves that are specific for the piece, the other things like getting out of the board should be handled in the game or board implementation
		virtual bool isValidMove(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY) = 0;

		bool getColor() const;
		char getType() const;
};

#endif