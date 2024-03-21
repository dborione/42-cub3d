/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:57:07 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/19 15:20:22 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include "cub3d_textures.h"

# define TILE_SIZE 32
# ifndef WIN_WIDTH
#  define WIN_WIDTH 1920
# endif
# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1080
# endif
# ifndef DISTANCE_FOR_FULL_WALL
#  define DISTANCE_FOR_FULL_WALL 6.7625
# endif

/* Directionts */

# define YAW_NORTH 0.0f
# define YAW_SOUTH 180.0f
# define YAW_WEST -90.0f
# define YAW_EAST 90.0f

# define NORTH_WALL 0
# define SOUTH_WALL 1
# define WEST_WALL 2
# define EAST_WALL 3

# define ROTATION_SPEED 0.15

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
typedef struct s_game {
	void				*mlx;
	void				*mlx_win;
	t_cub3d_textures	*textures;
	t_location			*player;
	int					rotate_left;
	int					rotate_right;
	float				player_dir_x;
	float				player_dir_y;
	float				camera_plane_x;
	float				camera_plane_y;
}						t_game;

// Init
int		ft_quit_window(t_game *game);
int		ft_init_game(t_game **game);
int		ft_raycasting(t_game *game);
void	ft_set_direction_and_camera(t_game *game);

#endif
