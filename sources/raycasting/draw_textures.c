/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:41:55 by dborione          #+#    #+#             */
/*   Updated: 2024/03/08 01:47:08 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include "../../includes/cub3d_raycasting.h"
#include "../../includes/cub3d_render.h"

void	ft_get_texture_pos(t_raycaster *raycaster)
{
	raycaster->line->texture_x = (int)(raycaster->line->wall_hit_x
			* WALL_WIDTH);
	if ((raycaster->ray->side == EAST_WALL || raycaster->ray->side
			== WEST_WALL) && raycaster->ray->dir_x > 0)
		raycaster->line->texture_x = WALL_WIDTH
			- raycaster->line->texture_x - 1;
	if ((raycaster->ray->side == NORTH_WALL || raycaster->ray->side
			== SOUTH_WALL) && raycaster->ray->dir_x < 0)
		raycaster->line->texture_x = WALL_WIDTH
			- raycaster->line->texture_x - 1;
	raycaster->line->step = 1.0 * WALL_HEIGHT / raycaster->line->height;
	raycaster->line->texture_pos = (raycaster->line->bottom - WIN_HEIGHT
			/ 2 + raycaster->line->height / 2) * raycaster->line->step;
	if ((raycaster->ray->side == EAST_WALL || raycaster->ray->side
			== WEST_WALL) && raycaster->ray->dir_x < 0)
		raycaster->line->text_num = 0;
	else if ((raycaster->ray->side == EAST_WALL || raycaster->ray->side
			== WEST_WALL) && raycaster->ray->dir_x >= 0)
		raycaster->line->text_num = 1;
	else if ((raycaster->ray->side == NORTH_WALL || raycaster->ray->side
			== SOUTH_WALL) && raycaster->ray->dir_y < 0)
		raycaster->line->text_num = 2;
	else if ((raycaster->ray->side == NORTH_WALL || raycaster->ray->side
			== SOUTH_WALL) && raycaster->ray->dir_y >= 0)
		raycaster->line->text_num = 3;
}
