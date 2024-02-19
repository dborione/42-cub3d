/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:57:07 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/02/19 14:29:01 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include "cub3d_textures.h"
#include <stdio.h>

# define TILE_SIZE 32
# ifndef WIDTH
#  define WIDTH 1920
# endif
# ifndef HEIGHT
#  define HEIGHT 1080
# endif

typedef struct s_location
{
	float	x;
	float	y;
	float	pitch;
	float	yaw;
}			t_location;

/* 
	Cette structure est utilisée tout le long du jeu 
	elle enregistre les éléments important tel que 
	les pointeurs pour la MLX, les textures et code 
	de la map
*/
typedef struct	s_game {
	void				*mlx;
	void				*mlx_win;
	t_cub3d_textures	*textures;
	t_location			*player;
	void				*minimap_img_ptr;
	int					minimap;
}						t_game;

/*
	Pour bien enregistrer la position du joueur il faudrait : 
	x + y (coordonées en float) et pitch + yaw (direction en float)
*/

// typedef struct s_player {
	// start pos(x, y)
	// direction (x, y)
	// field of view : plane perpendiculaire au player (x = 0, y)
// }

// Init
int	ft_quit_window(t_game *game);
int	ft_init_game(t_game **game);

#endif