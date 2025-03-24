


class Queen : public Piece 
{
	public:
		Queen(bool isWhite) : Piece(isWhite, 'Q') {}
		bool isValidMove(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY) override
		{
			return (abs(endY - startY) == abs(endX - startX)) ||
			 ((startX == endX) || (startY == endY));
		}
};