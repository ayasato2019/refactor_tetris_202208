#include "../includes/tetris.h"

int	move_down_shape(t_game *game, t_shape *temp, t_shape *current)
{
	int	removed_lines;

	temp->row++;
	if (check_placed(game->board, temp))
	{
		current->row++;
		return (0);
	}
	else
	{
		place_shape_to_board(game->board, current);
		removed_lines = remove_filled_lines(game);
		drop_new_shape(game, current);
		return (removed_lines);
	}
}

int	has_to_update(t_game *game)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	return (diff_time(&game->updated_at, &now) > game->timer);
}

void	print_game(t_game *game, t_shape *current)
{
	t_board	buffer = {0};

	place_shape_to_board(buffer, current);
	display_to_window(buffer, game);
}

void	game_loop_switch(t_game *game, t_shape *current, int c, t_shape temp)
{
	int	removed_lines;

	switch (c)
	{
		case KEY_QUICKEN:
		{
			removed_lines = move_down_shape(game, &temp, current);
			game->final += 100 * removed_lines;
			break ;
		}
		case KEY_MOVE_RIGHT:
			temp.col++;
		if (check_placed(game->board, &temp))
			current->col++;
		break ;
		case KEY_MOVE_LEFT:
			temp.col--;
		if (check_placed(game->board, &temp))
			current->col--;
		break ;
		case KEY_ROTATE:
			rotate_shape(&temp);
		if (check_placed(game->board, &temp))
			rotate_shape(current);
		break ;
	}
}

void	game_loop(t_game *game, t_shape *current)
{
	int		c;
	t_shape	temp;

	print_game(game, current);
	while (game->on)
	{
		c = getch();
		if (c != ERR)
		{
			temp = duplicate_shape(current);
			game_loop_switch(game, current, c, temp);
			destroy_shape(&temp);
			print_game(game, current);
		}
		if (has_to_update(game))
		{
			temp = duplicate_shape(current);
			{
				move_down_shape(game, &temp, current);
			}
			destroy_shape(&temp);
			print_game(game, current);
			gettimeofday(&game->updated_at, NULL);
		}
	}
}
