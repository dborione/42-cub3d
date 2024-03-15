/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:41:55 by dborione          #+#    #+#             */
/*   Updated: 2024/03/14 12:26:01 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include "../../includes/cub3d_raycasting.h"

// FOV = ratio between the length of the direction vector,
//	and the length of the plane.
t_raycaster	*ft_new_raycaster(t_game *game)
{
	t_raycaster	*raycaster;

	raycaster = malloc(sizeof(t_raycaster));
	if (!raycaster)
		return (NULL);
	raycaster->player_pos_x = game->player->x + 0.5;
	raycaster->player_pos_y = game->player->y + 0.5;
	raycaster->player_dir_x = game->player_dir_x;
	raycaster->player_dir_y = game->player_dir_y;
	raycaster->camera_plane_x = game->camera_plane_x;
	raycaster->camera_plane_y = game->camera_plane_y;
	raycaster->ray = ft_new_ray();
	if (!raycaster->ray)
	{
		free (raycaster);
		return (NULL);
	}
	raycaster->line = ft_new_line();
	if (!raycaster->line)
	{
		free(raycaster->ray);
		free (raycaster);
		return (NULL);
	}
	return (raycaster);
}

static
void	ft_cast_rays(t_raycaster *raycaster, int i)
{
	raycaster->ray->camera_pos_x = 2 * i / (float)WIN_WIDTH - 1;
	raycaster->ray->dir_x = raycaster->player_dir_x + raycaster->camera_plane_x
		* raycaster->ray->camera_pos_x;
	raycaster->ray->dir_y = raycaster->player_dir_y + raycaster->camera_plane_y
		* raycaster->ray->camera_pos_x;
	raycaster->ray->delta_dist_x = fabs(1 / raycaster->ray->dir_x);
	raycaster->ray->delta_dist_y = fabs(1 / raycaster->ray->dir_y);
}

void	ft_update_raycaster(t_game *game, t_raycaster *raycaster, int i)
{
	ft_clear_ray(raycaster->ray);
	ft_clear_line(raycaster->line);
	ft_cast_rays(raycaster, i);
	ft_dda_loop(game, raycaster);
	ft_get_wall_infos(game, raycaster);
	ft_get_texture_pos(raycaster);
}
