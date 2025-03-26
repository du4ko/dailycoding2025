#include "interfaces/headers/game.h"




int main()
{
	Game new_game;
	new_game.get_board().drawBoard();
	new_game.Move(1,0,2,0);
	new_game.get_board().drawBoard();

	return 0;

};