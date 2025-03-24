


class Pawn : public Piece{
	public:
		Pawn(bool isWhite) : Piece(isWhite, 'P') {}
		bool isValidMove(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY) override
		{
			if(isWhite)
			{
				if(startX == endX)
				{
					if(startY == 1 && (endY == startY + 1 || endY == startY + 2))
					{
						return true;
					}
					else if(endY == startY + 1)
					{
						return true;
					}
				}
			}
			else
			{
				if(startX == endX)
				{
					if(startY == 6 && (endY == startY - 1 || endY == startY - 2))
					{
						return true;
					}
					else if( endY == startY - 1)
					{
						return true;
					}
				}
			}
			return false;	
		}
};