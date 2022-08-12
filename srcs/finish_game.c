#include "../includes/tetris.h"

static void	display_result(t_game *game)
{
	int	i;
	int	j;

	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
			printf("%c ", game->board[i][j] ? '#': '.');
		printf("\n");
	}
	printf("\nGame over!\n");
	printf("\nScore: %d\n", game->final);
}

void	finish_game(t_game *game, t_shape *current)
{
	destroy_window();
	destroy_shape(current);
	display_result(game);
}
