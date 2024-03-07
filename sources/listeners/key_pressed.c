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
void	ft_player_movement(t_game *game, int keycode)
{
	if (game->player->yaw == YAW_NORTH)
	{
		// printf("wall: %c\n",game->textures->map[(int)((game->player->y / 3) + 1)][(int)game->player->x / 3]);
		if (keycode == W_KEY &&
			game->textures->map[(int)((game->player->y / 3) - 1)][(int)game->player->x / 3] == '0')
				game->player->y -= 1;
		if (keycode == S_KEY)
			// game->textures->map[(int)((game->player->y / 3) + 1)][(int)game->player->x / 3] == '0')
			game->player->y += 1;
		// else if (keycode == A_KEY)
		// 	// game->textures->map[(int)((game->player->y / 3) + 1)][(int)game->player->x / 3] == '0')
		// 	game->player->x -= 1;
		// else if (keycode == D_KEY)
		// 	game->player->x += 1;
	}
	if (game->player->yaw == YAW_SOUTH)
	{
		if (keycode == W_KEY)
			// game->textures->map[(int)((game->player->y / 3) - 1)][(int)game->player->x / 3] == '0')
				game->player->y += 1;
		else if (keycode == S_KEY)
			// game->textures->map[(int)((game->player->y / 3) + 1)][(int)game->player->x / 3] == '0')
				game->player->y -= 1;
	}
	// if (game->player->yaw == YAW_WEST)
	// {
	// 	if (keycode == W_KEY &&
	// 		game->textures->map[(int)((game->player->y / 3) - 1)][(int)game->player->x / 3] == '0')
	// 			game->player->y -= 1;
	// 	else if (keycode == S_KEY)
	// 		// game->textures->map[(int)((game->player->y / 3) + 1)][(int)game->player->x / 3] == '0')
	// 			game->player->y += 1;
	// }
	// if (game->player->yaw == YAW_EAST)
	// {
	// 	if (keycode == W_KEY &&
	// 		game->textures->map[(int)((game->player->y / 3) - 1)][(int)game->player->x / 3] == '0')
	// 			game->player->y -= 1;
	// 	else if (keycode == S_KEY)
	// 		// game->textures->map[(int)((game->player->y / 3) + 1)][(int)game->player->x / 3] == '0')
	// 			game->player->y += 1;
	// }
	// if (keycode == A_KEY)
	// 	game->player->x -= 1;
	// if (keycode == D_KEY)
	// 	game->player->x += 1;
	ft_render_frame(game);
}

static
int	ft_key_pressed(int keycode, t_game *game)
{
	if (keycode == UP_ARROW_KEY)
	{
		game->player->yaw = YAW_NORTH;
		ft_render_frame(game);
		// ft_draw_wall(game, game->textures->north_texture);
		// mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->frame->pointer, x, y);
	}
	else if (keycode == LEFT_ARROW_KEY)
	{
		game->player->yaw = YAW_WEST;
		ft_render_frame(game);
		// ft_draw_wall(game, game->textures->west_texture);
		// mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->frame->pointer, x, y);
	}
	else if (keycode == RIGHT_ARROW_KEY)
	{
		game->player->yaw = YAW_EAST;
		ft_render_frame(game);
		// ft_draw_wall(game, game->textures->east_texture);
		// mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->frame->pointer, x, y);
	}
	else if (keycode == DOWN_ARROW_KEY)
	{
		game->player->yaw = YAW_SOUTH;
		ft_render_frame(game);
		// ft_draw_wall(game, game->textures->south_texture);
		// mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->frame->pointer, x, y);
	}
	else if (keycode == W_KEY || keycode == A_KEY
		|| keycode == S_KEY || keycode == D_KEY)
		ft_player_movement(game, keycode);
	else if (keycode == ESC_KEY)
		ft_quit_window(game);
	return (0);
}

void	ft_key_hook_pressed(t_game *game)
{
	mlx_hook(game->mlx_win, 2, (1L<<0), ft_key_pressed, game);
}

