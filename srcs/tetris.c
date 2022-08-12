#include "../includes/tetris.h"

int	main(void)
{
	t_game	game;
	t_shape	current;

	init_game(&game, &current);
	game_loop(&game, &current);
	finish_game(&game, &current);
	return (0);
}
