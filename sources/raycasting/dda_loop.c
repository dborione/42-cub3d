/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:41:55 by dborione          #+#    #+#             */
/*   Updated: 2024/03/08 09:55:05 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include "../../includes/cub3d_raycasting.h"

/* 
    raycaster->ray->tile_dist_x = length of ray
	from current position to next x or y-side
*/
static
void	ft_get_tile_dist(t_raycaster *raycaster)
{
	if (raycaster->ray->dir_x < 0)
	{
		raycaster->ray->step_x = -1;
		raycaster->ray->tile_dist_x = (raycaster->player_pos_x
				- raycaster->ray->map_pos_x) * raycaster->ray->delta_dist_x;
	}
	else
	{
		raycaster->ray->step_x = 1;
		raycaster->ray->tile_dist_x = (raycaster->ray->map_pos_x + 1.0
				- raycaster->player_pos_x) * raycaster->ray->delta_dist_x;
	}
	if (raycaster->ray->dir_y < 0)
	{
		raycaster->ray->step_y = -1;
		raycaster->ray->tile_dist_y = (raycaster->player_pos_y
				- raycaster->ray->map_pos_y) * raycaster->ray->delta_dist_y;
	}
	else
	{
		raycaster->ray->step_y = 1;
		raycaster->ray->tile_dist_y = (raycaster->ray->map_pos_y
				+ 1.0 - raycaster->player_pos_y) * raycaster->ray->delta_dist_y;
	}
}

static
void	ft_do_dda(t_game *game, t_raycaster *raycaster)
{
	while (raycaster->ray->hit == 0)
	{
		if (raycaster->ray->tile_dist_x < raycaster->ray->tile_dist_y)
		{
			raycaster->ray->tile_dist_x += raycaster->ray->delta_dist_x;
			raycaster->ray->map_pos_x += raycaster->ray->step_x;
			if (raycaster->ray->map_pos_x < game->player->x)
				raycaster->ray->side = WEST_WALL;
			else
				raycaster->ray->side = EAST_WALL;
		}
		else
		{
			raycaster->ray->tile_dist_y += raycaster->ray->delta_dist_y;
			raycaster->ray->map_pos_y += raycaster->ray->step_y;
			if (raycaster->ray->map_pos_y < game->player->y)
				raycaster->ray->side = NORTH_WALL;
			else
				raycaster->ray->side = SOUTH_WALL;
		}
		if (game->textures->map[raycaster->ray->map_pos_y]
			[raycaster->ray->map_pos_x] == '1')
			raycaster->ray->hit = 1;
	}
}

static
void	ft_get_current_pos(t_raycaster *raycaster)
{
	raycaster->ray->map_pos_x = (int)raycaster->player_pos_x;
	raycaster->ray->map_pos_y = (int)raycaster->player_pos_y;
}

void	ft_dda_loop(t_game *game, t_raycaster *raycaster)
{
	ft_get_current_pos(raycaster);
	ft_get_tile_dist(raycaster);
	ft_do_dda(game, raycaster);
}
