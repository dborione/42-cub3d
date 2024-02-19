#include "../includes/cub3d.h"

int ft_init_game(t_game **game)
{
	*game = malloc(sizeof(t_game));
	if (!*game)
		return (0);
	(*game)->mlx = mlx_init();
    // if !(g->mlx)
        // quit free and exit

	(*game)->mlx_win = mlx_new_window((*game)->mlx, WIDTH, HEIGHT, "Cub3d");
	(*game)->textures = NULL;
	(*game)->player = NULL;
    return (1);
}
