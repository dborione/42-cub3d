/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:30:55 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/07 14:49:11 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/cub3d_render.h"
#include "../includes/cub3d_listeners.h"

static
void	ft_look_back(t_game *game)
{
	if (game->player->yaw == YAW_NORTH)
		game->player->yaw = YAW_SOUTH;
	else if (game->player->yaw == YAW_SOUTH)
		game->player->yaw = YAW_NORTH;
	else if (game->player->yaw == YAW_WEST)
		game->player->yaw = YAW_EAST;
	else if (game->player->yaw == YAW_EAST)
		game->player->yaw = YAW_WEST;
	ft_render_frame(game);
}

static
void	ft_look_right(t_game *game)
{
	if (game->player->yaw == YAW_NORTH)
		game->player->yaw = YAW_EAST;
	else if (game->player->yaw == YAW_EAST)
		game->player->yaw = YAW_SOUTH;
	else if (game->player->yaw == YAW_SOUTH)
		game->player->yaw = YAW_WEST;
	else if (game->player->yaw == YAW_WEST)
		game->player->yaw = YAW_NORTH;
	ft_render_frame(game);
}

static
void	ft_look_left(t_game *game)
{
	if (game->player->yaw == YAW_NORTH)
		game->player->yaw = YAW_WEST;
	else if (game->player->yaw == YAW_WEST)
		game->player->yaw = YAW_SOUTH;
	else if (game->player->yaw == YAW_SOUTH)
		game->player->yaw = YAW_EAST;
	else if (game->player->yaw == YAW_EAST)
		game->player->yaw = YAW_NORTH;
	ft_render_frame(game);
}

static
int	ft_key_pressed(int keycode, t_game *game)
{
	if (keycode == W_KEY || keycode == A_KEY
		|| keycode == S_KEY || keycode == D_KEY)
		ft_player_movement(game, keycode);
	else if (keycode == LEFT_ARROW_KEY)
		ft_look_left(game);
	else if (keycode == RIGHT_ARROW_KEY)
		ft_look_right(game);
	else if (keycode == DOWN_ARROW_KEY)
		ft_look_back(game);
	else if (keycode == ESC_KEY)
		ft_quit_window(game);
	return (0);
}

void	ft_key_hook_pressed(t_game *game)
{
	mlx_hook(game->mlx_win, 2, (1L<<0), ft_key_pressed, game);
}

