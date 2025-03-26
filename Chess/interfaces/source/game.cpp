#include "../headers/game.h"

Game::Game() : board(), white_player('W'), black_player('B') {}

bool Game::Move(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY)
{
	std::vector<std::vector<Piece*>>& boardRef = board.getBoard();
	boardRef[endX][endY] = boardRef[startX][startY];
	boardRef[startX][startY] = nullptr;
	return true;

}

Board Game::get_board() 
{
	return board;
}

Game::~Game() {}
