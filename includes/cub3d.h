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

int	ft_quit_window(t_game *g);

#endif