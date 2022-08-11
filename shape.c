#include "tetris.h"

const t_shape	Tetriminoes[7] = {
	{(char *[]){(char []){0, 1, 1}, (char []){1, 1, 0}, (char []){0, 0, 0}}, 3},
	{(char *[]){(char []){1, 1, 0}, (char []){0, 1, 1}, (char []){0, 0, 0}}, 3},
	{(char *[]){(char []){0, 1, 0}, (char []){1, 1, 1}, (char []){0, 0, 0}}, 3},
	{(char *[]){(char []){0, 0, 1}, (char []){1, 1, 1}, (char []){0, 0, 0}}, 3},
	{(char *[]){(char []){1, 0, 0}, (char []){1, 1, 1}, (char []){0, 0, 0}}, 3},
	{(char *[]){(char []){1, 1}, (char []){1, 1}}, 2},
	{(char *[]){(char []){0, 0, 0, 0}, (char []){1, 1, 1, 1},
	(char []){0, 0, 0, 0}, (char []){0, 0, 0, 0}}, 4}
};

t_shape	duplicate_shape(const t_shape *shape)
{
	t_shape	new_shape;
	char	**copyshape;
	int		i;

	i = 0;
	new_shape = *shape;
	copyshape = shape->array;
	new_shape.array = (char **)malloc(new_shape.width * sizeof(char *));
	for (i = 0; i < new_shape.width; i++)
	{
		new_shape.array[i] = (char *)malloc(new_shape.width * sizeof(char));
		memcpy(&new_shape.array[i][0], &copyshape[i][0],
							new_shape.width * sizeof(char));
	}
	return (new_shape);
}

void	destroy_shape(t_shape *shape)
{
	int	i;

	for (i = 0; i < shape->width; i++)
	{
		free(shape->array[i]);
	}
	free(shape->array);
}

void	rotate_shape(t_shape *shape)
{
	t_shape	temp;
	int		width;
	int		i;
	int		j;
	int		k;

	temp = duplicate_shape(shape);
	width = shape->width;
	for (i = 0; i < width; i++)
	{
		for (j = 0, k = width - 1; j < width; j++, k--)
		{
			shape->array[i][j] = temp.array[k][i];
		}
	}
	destroy_shape(&temp);
}

void	drop_new_shape(t_game *game, t_shape *current)
{
	t_shape	new_shape;

	new_shape = duplicate_shape(&Tetriminoes[rand() % 7]);
	new_shape.col = rand() % (C - new_shape.width + 1);
	new_shape.row = 0;
	destroy_shape(current);
	*current = new_shape;
	if (!check_placed(game->board, current))
		game->on = false;
}
