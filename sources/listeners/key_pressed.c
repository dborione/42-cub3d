/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:30:55 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/14 12:25:22 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/cub3d_render.h"
#include "../includes/cub3d_listeners.h"

static
void	ft_look_right(t_game *game)
{
	game->rotate_right = 1;
	ft_render_frame(game);
}

static
void	ft_look_left(t_game *game)
{
	game->rotate_left = 1;
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
	else if (keycode == ESC_KEY)
		ft_quit_window(game);
	return (0);
}

static
int	ft_key_released(int keycode, t_game *game)
{
	if (keycode == LEFT_ARROW_KEY)
		game->rotate_left = 0;
	if (keycode == RIGHT_ARROW_KEY)
		game->rotate_right = 0;
	return (0);
}

void	ft_key_hook_pressed(t_game *game)
{
	mlx_hook(game->mlx_win, ON_KEY_DOWN, ON_KEY_PRESS, ft_key_pressed, game);
	mlx_hook(game->mlx_win, ON_KEY_UP, ON_KEY_RELEASE, ft_key_released, game);
}
