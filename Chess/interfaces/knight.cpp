


class Knight : public Piece
{
	public:
	Knight(bool isWhite) : Piece(isWhite, 'N') {}
	bool isValidMove(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY) override
	{
		//using absolute to cover the negative if the knight is black
		int dx = abs(endX - startX);
		int dy = abs(endY - startY);
		
		return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
	}
}