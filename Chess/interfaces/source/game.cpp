#include "../headers/game.h"
#include <iostream>

Game::Game() : board(), white_player('W'), black_player('B') {}\

//TODO function that check if there is collision and pieces are unable to pass or needs to take
bool Game::checkCollision(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY, Piece piece_to_move)
{
	std::vector<std::vector<Piece*>>& boardRef = board.getBoard();
	Piece l_piece = piece_to_move;
	char piece_type = l_piece.getType();
	bool piece_color = l_piece.getColor();

	if("P" == piece_type)
	{
		if(piece_color == "W")
		{
			//check two position ahead if its in start position (special move) it is checked if possible in the implementation of the piece
			if(abs(startY - endY) == 2 && nullptr == boardRef[startX][startY + 1] && nullptr == boardRef[startX][startY + 2])
			{
				return true;
			}
			//normal move check
			if(abs(startY - endY) == 1 && nullptr == boardRef[startX][endY])
			{
				return true;
			}
		}
		if(piece_color == "B")
		{
			//check two position ahead if its in start position (special move) it is checked if possible in the implementation of the piece
			if(abs(startY - endY) == 2 && nullptr == boardRef[startX][startY - 1] && nullptr == boardRef[startX][startY - 2])
			{
				return true;
			}
			//normal move check
			if(abs(startY - endY) == 1 && nullptr == boardRef[startX][endY])
			{
				return true;
			}
		}	
	}
	else if("K" == piece_type){} 
	else if("Q" == piece_type){}
	else if("R" == piece_type){}
	else if("N" == piece_type){}
	else if("B" == piece_type){}
	return true; 
}
	 

bool Game::Move(uint8_t startX, uint8_t startY, uint8_t endX, uint8_t endY)
{
	//first we check if the cordinates are valid (are in the board square)
	if(startX > 8 || startY > 8 || endX > 8 || endY > 8)
	{
		std::cout << "Invalid cordinates" << std::endl;
		return false;
	}

	//create a reference to the board
	std::vector<std::vector<Piece*>>& boardRef = board.getBoard();
	//get piece to check if the move is legit (collision, type of movement)
	Piece piece_to_move = boardRef[startX][startY];

	//check if there is a piece in the selected cordinates
	if(nullptr == boardRef[startX][startY])
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

	if(true)
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
