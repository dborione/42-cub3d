#include <mlx.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_game {
	void	*mlx;
	void	*mlx_win;
}				t_game;

int	ft_red_cross(t_game *g)
{
	mlx_destroy_window(g->mlx, g->mlx_win);
	exit (0);
}

int	main(void)
{
	t_game	g;
	t_data	img;

	g.mlx = mlx_init();
	g.mlx_win = mlx_new_window(g.mlx, 1920, 1080, "Cub3d");
	img.img = mlx_new_image(g.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(g.mlx, g.mlx_win, img.img, 0, 0);
	mlx_hook(g.mlx_win, 17, 0, ft_red_cross, &g);
	mlx_loop(g.mlx);
}

