/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:14:06 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/02/06 15:39:50 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/cub3d_render.h"
#include "../includes/cub3d_listeners.h"
#include <stdio.h>

int	ft_key_hook_disable(int keycode, t_game *game)
{
	int	x;
	int	y;
	int	color;

	if (keycode == R_KEY)
		color = 0x00FF0000;
	else if (keycode == G_KEY)
		color = 0x0000FF00;
	else if (keycode == B_KEY)
		color = 0x000000FF;
	else
		color = 0x00FFFFFF;
	y = 0;
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			mlx_pixel_put(game->mlx, game->mlx_win, x, y, color);
			x++;
		}
		y++;
	}
	//ft_render_wall(game, 4, 0);
	return (0);
}

int	ft_key_hook(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	
	if (keycode == T_KEY)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->test, x, y);
	}
	else if (keycode == M_KEY)
	{
		printf("%d\n", game->minimap);
		if (game->minimap != 0) // minimap is already on screen
		{
			printf("destroying minimap\n");
			mlx_destroy_image(game->mlx, game->minimap_img_ptr);
			// a changer plus tard car reset la window
			mlx_clear_window(game->mlx, game->mlx_win);
			ft_render_frame(game);
			game->minimap = 0;
		}
		else
			ft_render_minimap(game);
	}
	else if (keycode == W_KEY || keycode == UP_ARROW_KEY)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->north_texture, x, y);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->north_texture, x + 720, y);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->north_texture, x + 1440, y);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->north_texture, x, y + 480);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->north_texture, x + 720, y + 480);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->north_texture, x + 1440, y + 480);
	}
	else if (keycode == A_KEY || keycode == LEFT_ARROW_KEY)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->west_texture, x, y);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->west_texture, x + 720, y);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->west_texture, x + 1440, y);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->west_texture, x, y + 480);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->west_texture, x + 720, y + 480);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->west_texture, x + 1440, y + 480);
	}
	else if (keycode == D_KEY || keycode == RIGHT_ARROW_KEY)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->east_texture, x, y);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->east_texture, x + 720, y);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->east_texture, x + 1440, y);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->east_texture, x, y + 480);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->east_texture, x + 720, y + 480);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->east_texture, x + 720, y + 480);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->east_texture, x + 1440, y + 480);
	}
	else if (keycode == S_KEY || keycode == DOWN_ARROW_KEY)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->south_texture, x, y);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->south_texture, x + 720, y);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->south_texture, x + 1440, y);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->south_texture, x, y + 480);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->south_texture, x + 720, y + 480);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->south_texture, x + 720, y + 480);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->south_texture, x + 1440, y + 480);
	}
	else if (keycode == ESC_KEY)
		ft_quit_window(game);
	else
		ft_draw_frame(game);
	return (0);
}