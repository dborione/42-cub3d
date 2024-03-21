/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycasting.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:41:55 by dborione          #+#    #+#             */
/*   Updated: 2024/03/19 15:23:45 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAYCASTING_H
# define CUB3D_RAYCASTING_H
# include "cub3d.h"
# include "../libft/libft.h"

# include <math.h>
# include <limits.h>

typedef struct s_line
{
	float	wall_hit_x;
	int		height;
	int		bottom;
	int		top;
	int		texture_x;
	int		texture_y;
	float	texture_pos;
	float	texture_map_pos;
	float	step;
	int		text_num;
}	t_line;

typedef struct s_ray
{
	float	camera_pos_x;
	float	dir_x;
	float	dir_y;
	int		map_pos_x;
	int		map_pos_y;
	int		last_map_pos_x;
	int		last_map_pos_y;
	float	tile_dist_x;
	float	tile_dist_y;
	float	delta_dist_x;
	float	delta_dist_y;
	int		hit;
	int		side;
	int		step_x;
	int		step_y;
	float	ray_to_wall_dist;
}	t_ray;

typedef struct s_raycaster
{
	float	player_pos_x;
	float	player_pos_y;
	float	player_dir_x;
	float	player_dir_y;
	float	camera_plane_x;
	float	camera_plane_y;
	char	wall_id;
	t_ray	*ray;
	t_line	*line;
}	t_raycaster;

void		ft_dda_loop(t_game *game, t_raycaster *raycaster);
void		ft_get_wall_infos(t_game *game, t_raycaster *raycaster);
void		ft_get_texture_pos(t_raycaster *raycaster);

/* News */

t_raycaster	*ft_new_raycaster(t_game *game);
t_ray		*ft_new_ray(void);
t_line		*ft_new_line(void);

/* Clears */

void		ft_clear_line(t_line *line);
void		ft_clear_ray(t_ray *ray);

/* Update */

void		ft_update_raycaster(t_game *game, t_raycaster *raycaster, int i);

void		ft_update_player_direction(t_game *game);

#endif
