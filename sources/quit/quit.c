#include "../includes/cub3d.h"

int	ft_quit_window(t_game *g)
{
	mlx_destroy_window(g->mlx, g->mlx_win);
	exit (0);
}