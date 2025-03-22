


class Piece
{
	protected:
		bool isWhite; //true for white, false for black
		char Type; //the type of the piece (pawn , bishop and etc)
	public:
		Piece(bool isWhite, char Type) : isWhite(isWhite), Type(Type) {}
		//Make sure the destructor is virtual as we inted to use polymorphism (virtual keyword make sure the compiler frees all memory upon destroing the object)
		virtual ~Piece() = default;
		virtual bool isValidMove(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY) = 0;

		bool getColor() const {return isWhite};
		char getType() const {return Type};
}