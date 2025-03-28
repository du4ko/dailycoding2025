#include "../headers/game.h"
#include <iostream>

Game::Game() : board(), white_player('W'), black_player('B') {}\

//TODO function that check if there is collision and pieces are unable to pass or needs to take
bool Game::checkCollision()
{

}

bool Game::Move(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY)
{
	//first we check if the cordinates are valid (are in the board square)
	if(startX > 8 || startY > 8 || endX > 8 || endY > 8 )
	{
		std::cout << "Invalid cordinates" << std::endl;
		return false;
	}

	//create a reference to the board
	std::vector<std::vector<Piece*>>& boardRef = board.getBoard();

	//check if there is a piece in the selected cordinates
	if(boardRef[startX][startY] == nullptr)
	{
		std::cout << "No piece on selected cordinates" << std::endl;
		return false;
	}

	//check if the cordinates are valid for the particular piece, every piece got its own implementation of the isValidMove function
	if(!(boardRef[startX][startY].isValidMove(startX, startY, endX, endY))
	{
		std::cout << "Move is invalid for this piece" << std::endl;
		return false;
	}

	if()
	{	
		
		boardRef[endX][endY] = boardRef[startX][startY];
		boardRef[startX][startY] = nullptr;
	}
	return true;

}

Board Game::get_board() 
{
	return board;
}

bool Game::getIsWhiteTurn()
{
	return isWhiteTurn;
}

void Game::setIsWhiteTurn(bool color)
{
	isWhiteTurn = color;
}

Game::~Game() {}
