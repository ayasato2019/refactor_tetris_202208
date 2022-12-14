#include "../includes/tetris.h"

bool	check_placed(t_board board, const t_shape *shape)
{
	char	**array;
	int		i;
	int		j;

	array = shape->array;
	for (i = 0; i < shape->width; i++)
	{
		for (j = 0; j < shape->width; j++)
		{
			if ((shape->col + j < 0 || shape->col + j >= C || shape->row + i >= R))
			{
				if (array[i][j])
					return (false);
			}
			else if (board[shape->row + i][shape->col + j] && array[i][j])
				return (false);
		}
	}
	return (true);
}

void	place_shape_to_board(t_board board, const t_shape *shape)
{
	for (int i = 0; i < shape->width; i++)
	{
		for (int j = 0; j < shape->width; j++)
			board[shape->row + i][shape->col + j] |= shape->array[i][j];
	}
}

int	remove_filled_lines(t_game *game)
{
	int	count;
	int	n;
	int	m;
	int	sum;
	int	k;

	count = 0;
	for (n = 0; n < R; n++)
	{
		sum = 0;
		for (m = 0; m < C; m++)
			sum += game->board[n][m];
		if (sum == C)
		{
			count++;
			for (k = n; k >= 1; k--)
				memcpy(&game->board[k][0], &game->board[k - 1][0], sizeof(char) * C);
			memset(&game->board[k][0], 0, sizeof(char) * C);
			game->timer -= game->decrease--;
		}
	}
	return (count);
}
