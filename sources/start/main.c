#include "../includes/cub3d.h"

int	main(void)
{
	t_game	g;
	t_data	img;

	// init struct
	// parse map
		// init raycasting
	// movemnt
	g.mlx = mlx_init();
	g.mlx_win = mlx_new_window(g.mlx, 1920, 1080, "Cub3d");
	img.img = mlx_new_image(g.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(g.mlx, g.mlx_win, img.img, 0, 0);
	mlx_hook(g.mlx_win, 17, 0, ft_quit_window, &g);
	mlx_loop(g.mlx);
}

