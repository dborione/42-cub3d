#ifndef CUB3D_H
    # define CUB3D_H

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

// typedef struct s_player {
	// start pos(x, y)
	// direction (x, y)
	// field of view : plane perpendiculaire au player (x = 0, y)
// }

// Init
int	ft_quit_window(t_game *g);
int	ft_init_game(t_game *g, t_data *img);

#endif