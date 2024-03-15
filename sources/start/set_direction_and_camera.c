/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direction_and_camera.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:38:49 by dborione          #+#    #+#             */
/*   Updated: 2024/03/14 12:38:50 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static
void	ft_set_player_direction(t_game *game)
{
	if (game->player->yaw == YAW_NORTH)
		game->player_dir_y = -1;
	else if (game->player->yaw == YAW_SOUTH)
		game->player_dir_y = 1;
	else if (game->player->yaw == YAW_WEST || game->player->yaw == YAW_EAST)
		game->player_dir_y = 0;
	if (game->player->yaw == YAW_WEST)
		game->player_dir_x = -1;
	else if (game->player->yaw == YAW_EAST)
		game->player_dir_x = 1;
	else if (game->player->yaw == YAW_NORTH || game->player->yaw == YAW_SOUTH)
		game->player_dir_x = 0;
}

static
void	ft_set_camera_plane(t_game *game)
{
	if (game->player->yaw == YAW_NORTH)
		game->camera_plane_x = 0.66;
	else if (game->player->yaw == YAW_SOUTH)
		game->camera_plane_x = -0.66;
	else if (game->player->yaw == YAW_WEST || game->player->yaw == YAW_EAST)
		game->camera_plane_x = 0;
	if (game->player->yaw == YAW_WEST)
		game->camera_plane_y = -0.66;
	else if (game->player->yaw == YAW_EAST)
		game->camera_plane_y = 0.66;
	else if (game->player->yaw == YAW_NORTH || game->player->yaw == YAW_SOUTH)
		game->camera_plane_y = 0;
}

void	ft_set_direction_and_camera(t_game *game)
{
	ft_set_player_direction(game);
	ft_set_camera_plane(game);
}
