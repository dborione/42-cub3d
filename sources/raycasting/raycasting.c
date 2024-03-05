/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:41:55 by dborione          #+#    #+#             */
/*   Updated: 2024/03/05 14:15:35 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include "../../includes/cub3d_raycasting.h"

static
void    ft_set_player_direction(t_game *game, t_raycaster *raycaster)
{
    if (game->player->yaw == 0.0f) //NORTH
        raycaster->player_dir_x = -1;
    else if (game->player->yaw == 180.0f) //SOUTH
        raycaster->player_dir_x = 1;
    else if (game->player->yaw == -90.0f || game->player->yaw == 90.0f) //WEST/EAST
        raycaster->player_dir_x = 0;
	if (game->player->yaw == -90.0f) //WEST
        raycaster->player_dir_y = -1;
    else if (game->player->yaw == 90.0f) //EAST
        raycaster->player_dir_y = 1;
    else if (game->player->yaw == 0.0f || game->player->yaw == 180.0f) //NORTH/SOUTH
        raycaster->player_dir_y = 0;
}

static
float    ft_set_camera_plane_x(t_game *game, t_raycaster *raycaster)
{
    if (game->player->yaw == -90.0f) //WEST
        raycaster->camera_plane_x = -0.66;
    else if (game->player->yaw == 90.0f) //EAST
        raycaster->camera_plane_x = 0.66;
    else if (game->player->yaw == 0.0f || game->player->yaw == 180.0f) //NORTH/SOUTH
        raycaster->camera_plane_x = 0;
    return (raycaster->camera_plane_x);
}

static
float    ft_set_camera_plane_y(t_game *game, t_raycaster *raycaster)
{
    if (game->player->yaw == 0.0f) //NORTH
        raycaster->camera_plane_y = 0.66;
    else if (game->player->yaw == 180.0f) //SOUTH
        raycaster->camera_plane_y = -0.66;
    else if (game->player->yaw == -90.0f || game->player->yaw == 90.0f) //WEST/EAST
        raycaster->camera_plane_y = 0;
    return (raycaster->camera_plane_y);
}

// FOV = ratio between the length of the direction vector, and the length of the plane.
t_raycaster   *ft_new_raycaster(t_game *game)
{
	t_raycaster	*raycaster;

    raycaster = malloc(sizeof(t_raycaster));
    if (!raycaster)
        return (NULL);
    raycaster->player_pos_x = game->player->x / 3;
    raycaster->player_pos_y = game->player->y / 3;
    ft_set_player_direction(game, raycaster);
    raycaster->camera_plane_x = ft_set_camera_plane_x(game, raycaster);
    raycaster->camera_plane_y = ft_set_camera_plane_y(game, raycaster);
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

void	ft_update_raycaster(t_game *game, t_raycaster *raycaster)
{
    // raycaster->player_pos_x = game->player->x / 3; pas besoin car la position du joueur ne change pas
    // raycaster->player_pos_y = game->player->y / 3;
    ft_set_player_direction(game, raycaster);
    raycaster->camera_plane_x = ft_set_camera_plane_x(game, raycaster);
    raycaster->camera_plane_y = ft_set_camera_plane_y(game, raycaster);
    ft_clear_ray(raycaster->ray);
    ft_clear_line(raycaster->line);
}
