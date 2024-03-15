/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:26:15 by dborione          #+#    #+#             */
/*   Updated: 2024/03/14 12:26:17 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/cub3d_raycasting.h"

static
void	ft_rotate(t_game *game, int factor)
{
	float	rot_speed;
	float	old_player_dir_x;
	float	old_camera_plane_x;
	
	rot_speed = ROTATION_SPEED;
	old_player_dir_x = game->player_dir_x;
	old_camera_plane_x = game->camera_plane_x;
	rot_speed *= factor;
	game->player_dir_x = game->player_dir_x * cos(rot_speed)
		- game->player_dir_y * sin(rot_speed);
	game->player_dir_y = old_player_dir_x * sin(rot_speed)
		+ game->player_dir_y * cos(rot_speed);
	game->camera_plane_x = game->camera_plane_x * cos(rot_speed)
		- game->camera_plane_y * sin(rot_speed);
	game->camera_plane_y = old_camera_plane_x * sin(rot_speed)
		+ game->camera_plane_y * cos(rot_speed);
}

void	ft_update_player_direction(t_game *game)
{
	if (game->rotate_left == 1)
		ft_rotate(game, -1);
	if (game->rotate_right == 1)
		ft_rotate(game, 1);
}
