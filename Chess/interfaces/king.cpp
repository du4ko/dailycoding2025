


class King : public Piece
{
	public:
		King(bool isWhite) : Piece(isWhite, 'K') {}
		bool isValidMove(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY) override
		{
			return abs(startX - endX) == 1 || abs(startY - endY) == 1 || (abs(startX - endX) == 1 && abs(startY - endY) == 1);
		}
}