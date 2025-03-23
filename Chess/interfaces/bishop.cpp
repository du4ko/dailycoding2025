


class Bishop : public Piece 
{
	public:
		Bishop(bool isWhite) : Piece(isWhite, 'B') {}
		bool isValidMove(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY) override
		{
			return abs(endY - startY) == abs(endX - startX);
		}
}