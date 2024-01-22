#include "../includes/cub3d.h"

int ft_init_game(t_game *game, t_data *img)
{
	game->mlx = mlx_init();
    // if !(g->mlx)
        // quit free and exit
	game->mlx_win = mlx_new_window(game->mlx, 1920, 1080, "Cub3d");
	img->img = mlx_new_image(game->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
	game->textures = NULL;
    return (1);
}