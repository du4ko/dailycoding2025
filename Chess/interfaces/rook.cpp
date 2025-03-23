


class Rook : Piece
{
	public:
		Rook(bool isWhite) : Piece(isWhite, 'R') {}
		bool isValidMove(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY) override
		{
			return (startX == endX) || (startY == endY)
		}
}