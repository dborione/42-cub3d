#include "../includes/cub3d.h"

int ft_init_game(t_game *g, t_data *img)
{
	g->mlx = mlx_init();
    // if !(g->mlx)
        // quit free and exit
	g->mlx_win = mlx_new_window(g->mlx, 1920, 1080, "Cub3d");
	img->img = mlx_new_image(g->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
    return (1);
}