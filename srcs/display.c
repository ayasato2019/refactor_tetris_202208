#include "../includes/tetris.h"

void	create_window(void)
{
	initscr();
	timeout(1);
}

void	display_to_window(t_board buffer, t_game *game)
{
	int	i;
	int	j;

	clear();
	for (i = 0; i < C - 9; i++)
		printw(" ");
	printw("42 Tetris\n");
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
			printw("%c ", (game->board[i][j] + buffer[i][j]) ? '#' : '.');
		printw("\n");
	}
	printw("\nScore: %d\n", game->final);
}

void	destroy_window(void)
{
	endwin();
}
