#include "interfaces/board.cpp"
#include "interfaces/pawn.cpp"
#include "interfaces/knight.cpp"
#include "interfaces/bishop.cpp"
#include "interfaces/king.cpp"
#include "interfaces/queen.cpp"
#include "interfaces/piece.cpp"


void main()
{
	Board mn_board = new Board();
	mn_board.drawBoard();

}