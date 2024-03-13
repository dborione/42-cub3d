/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:41:55 by dborione          #+#    #+#             */
/*   Updated: 2024/03/07 15:46:30 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include "../../includes/cub3d_raycasting.h"

static
void    ft_set_player_direction(t_game *game, t_raycaster *raycaster)
{
    if (game->player->yaw == YAW_NORTH)
        raycaster->player_dir_y = -1;
    else if (game->player->yaw == YAW_SOUTH)
        raycaster->player_dir_y = 1;
    else if (game->player->yaw == YAW_WEST || game->player->yaw == YAW_EAST)
        raycaster->player_dir_y = 0;
	if (game->player->yaw == YAW_WEST)
        raycaster->player_dir_x = -1;
    else if (game->player->yaw == YAW_EAST)
        raycaster->player_dir_x = 1;
    else if (game->player->yaw == YAW_NORTH || game->player->yaw == YAW_SOUTH)
        raycaster->player_dir_x = 0;
}

static
void    ft_set_camera_plane(t_game *game, t_raycaster *raycaster)
{
    if (game->player->yaw == YAW_NORTH)
        raycaster->camera_plane_x = 0.66;
    else if (game->player->yaw == YAW_SOUTH)
        raycaster->camera_plane_x = -0.66;
    else if (game->player->yaw == YAW_WEST || game->player->yaw == YAW_EAST)
        raycaster->camera_plane_x = 0;
	if (game->player->yaw == YAW_WEST)
        raycaster->camera_plane_y = -0.66;
    else if (game->player->yaw == YAW_EAST)
        raycaster->camera_plane_y = 0.66;
    else if (game->player->yaw == YAW_NORTH || game->player->yaw == YAW_SOUTH)
        raycaster->camera_plane_y = 0;
}

// FOV = ratio between the length of the direction vector, and the length of the plane.
t_raycaster   *ft_new_raycaster(t_game *game)
{
	t_raycaster	*raycaster;

    raycaster = malloc(sizeof(t_raycaster));
    if (!raycaster)
        return (NULL);
    raycaster->player_pos_x = game->player->x + 0.5;// / 3 + 1;
    raycaster->player_pos_y = game->player->y + 0.5;// / 3 + 1;
    ft_set_player_direction(game, raycaster);
    ft_set_camera_plane(game, raycaster);
    // printf("\npl_dir_x: %f, pl_dir_y: %f, camera_dir_x: %f, camera_dir_y: %f\n",
    //     raycaster->player_dir_x, raycaster->player_dir_y, raycaster->camera_plane_x, raycaster->camera_plane_y);
    // printf("player_x: %f, player_y: %f\n", game->player->x / 3, game->player->y / 3);
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
void    ft_cast_rays(t_raycaster *raycaster, int i)
{

    raycaster->ray->camera_pos_x = 2 * i / (float)WIN_WIDTH - 1;
    raycaster->ray->dir_x = raycaster->player_dir_x + raycaster->camera_plane_x
        * raycaster->ray->camera_pos_x;
    raycaster->ray->dir_y = raycaster->player_dir_y + raycaster->camera_plane_y
        * raycaster->ray->camera_pos_x;
    // check if raycaster->ray->dir_x ou raycaster->ray->dir_y == 0 pour la division
    // if (raycaster->ray->dir_x == 0)
    //     raycaster->ray->dir_x = INT_MAX;
    // if (raycaster->ray->dir_y == 0)
    //     raycaster->ray->dir_y = INT_MAX;
    // raycaster->ray->delta_dist = length of ray from one x or y-side to next x or y-side
    raycaster->ray->delta_dist_x = fabs(1 / raycaster->ray->dir_x);
    raycaster->ray->delta_dist_y = fabs(1 / raycaster->ray->dir_y);
}

void	ft_update_raycaster(t_game *game, t_raycaster *raycaster, int i)
{
    // raycaster->player_pos_x = game->player->x / 3; pas besoin car la position du joueur ne change pas
    // raycaster->player_pos_y = game->player->y / 3;
    // ft_set_player_direction(game, raycaster); en fait la direction non plus ne change pas
	// ft_set_camera_plane(game, raycaster);
    ft_clear_ray(raycaster->ray);
    ft_clear_line(raycaster->line);
	ft_cast_rays(raycaster, i);
	ft_dda_loop(game, raycaster);
	ft_get_wall_infos(game, raycaster);
	ft_get_texture_pos(raycaster);
}
