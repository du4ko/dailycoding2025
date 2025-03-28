#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

class Game
{
	private:
		Board board;
		Player white_player;
		Player black_player;
		bool isWhiteTurn;
	public:
		Game();
		~Game();
		bool Move(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY);
		Board get_board();
		bool getIsWhiteTurn();
		void setIsWhiteTurn(bool color = true);
		bool checkCollision(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY);
		
};

#endif