/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:28:03 by dborione          #+#    #+#             */
/*   Updated: 2024/03/14 12:28:07 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/cub3d_render.h"
#include "../includes/cub3d_listeners.h"

static
void	ft_move_back(t_game *game, float move_speed, float factor)
{
	if (game->textures->map[(int)(game->player->y + 0.5)][(int)((game->player->x
	+ 0.5) + game->player_dir_x * move_speed * factor)] == '0')
	{
		game->player->x += game->player_dir_x * move_speed * factor;
	}
	if (game->textures->map[(int)((game->player->y + 0.5)
			+ game->player_dir_y * move_speed * factor)][(int)(game->player->x
			+ 0.5)] == '0')
	{
		game->player->y += game->player_dir_y * move_speed * factor;
	}
}

static
void	ft_move_sides(t_game *game, float move_speed, float factor)
{
	if (game->textures->map[(int)(game->player->y + 0.5)][(int)((game->player->x
		+ 0.5) + game->camera_plane_x * move_speed * factor)] == '0')
	{
		game->player->x += game->camera_plane_x * move_speed * factor;
	}
	if (game->textures->map[(int)((game->player->y + 0.5)
			+ game->camera_plane_y * move_speed * factor)][(int)(game->player->x
			+ 0.5)] == '0')
	{
		game->player->y += game->camera_plane_y * move_speed * factor;
	}
}

void	ft_player_movement(t_game *game, int keycode)
{
	float	move_speed;

	move_speed = ROTATION_SPEED;
	if (keycode == W_KEY)
		ft_move_back(game, move_speed, 1);
	if (keycode == S_KEY)
		ft_move_back(game, move_speed, -1);
	if (keycode == D_KEY)
		ft_move_sides(game, move_speed, 1);
	if (keycode == A_KEY)
		ft_move_sides(game, move_speed, -1);
	ft_render_frame(game);
}
