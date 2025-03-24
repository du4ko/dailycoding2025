#include <vector>
#include "pawn.cpp"
#include "knight.cpp"
#include "bishop.cpp"
#include "king.cpp"
#include "queen.cpp"
#include "piece.cpp"


class Board
{
	private:
		std::std::vector<std::vector<Piece*>> board;
	public:
		Board() : board(8,std::vector<Piece*>(8, nullptr)) {initializeBoard();}

		void initializeBoard()
		{
			//initialize rooks for white
			board[0][0] = new Rook(true);
			board[0][7] = new Rook(true);

			//initialize rooks for black
			board[7][0] = new Rook(false);
			board[7][7] = new Rook(false);

			//initialize knights for white
			board[0][1] = new Knight(true);
			board[0][6] = new Knight(true);

			//initialize knights for black
			board[7][1] = new Knight(false);
			board[7][6] = new Knight(false);

			//initialize bishops for white
			board[0][2] = new Bishop(true);
			board[0][5] = new Bishop(true);

			//initialize bishops for black
			board[7][2] = new Bishop(false);
			board[7][5] = new Bishop(false);

			//initialize white queen
			board[0][3] = new Queen(true);

			//initialize black queen
			board[7][3] = new Queen(false);

			//initialize white king
			board[0][4] = new King(true);

			//initialize black king
			board[7][4] = new King(true);

			//initialize white pawns and black
			for(int i = 0; i < 8; i++)
			{
				//white pawn
				board[1][i] = new Pawn(true);
				board[6][i] = new Pawn(false);
			}
		}

		void drawBoard()
		{
			for(int i = 0; i < 8; i++)
			{
				for(int k = 0; k < 8; k++)
				{
					std::cout << "| " << (board[i][k] ? board[i][k]->getType() : ' ') << " ";
				}
				std::cout << std::endl;
			}
		}

};