#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "piece.h"


class Board
{
	private:
		std::vector<std::vector<Piece*>> board;
	public:
		Board();
		~Board();
		void initializeBoard();
		void drawBoard();
		std::vector<std::vector<Piece*>>& getBoard();
};

#endif