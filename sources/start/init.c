#include "../includes/cub3d.h"

/* TEST */
static
void    ft_init_buffer(t_game *game)
{
    int	i;
	int	j;

	i = -1;
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
			game->buf[i][j] = 0;
	}
}

int ft_init_game(t_game **game)
{
	*game = malloc(sizeof(t_game));
	if (!*game)
		return (0);
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
	{
		free(*game);
		return (0);
	}
	(*game)->mlx_win = mlx_new_window((*game)->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	(*game)->textures = NULL;
	(*game)->player = NULL;
	ft_init_buffer(*game);
    return (1);
}
