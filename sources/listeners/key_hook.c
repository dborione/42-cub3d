/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:14:06 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/01 13:38:32 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/cub3d_render.h"
#include "../includes/cub3d_listeners.h"

int	ft_key_hook(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	
	if (keycode == T_KEY)
	{
		ft_draw_frame(game);
		//mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->test, x, y);
	}
	// else if (keycode == M_KEY)
	// {
	// 	if (game->minimap != 0) // minimap is already on screen
	// 	{
	// 		printf("destroying minimap\n");
	// 		mlx_destroy_image(game->mlx, game->minimap_img_ptr);
	// 		// a changer plus tard car reset la window
	// 		mlx_clear_window(game->mlx, game->mlx_win);
	// 		ft_render_frame(game);
	// 		game->minimap = 0;
	// 	}
	// 	else
	// 		ft_render_minimap(game);
	// }
	else if (keycode == W_KEY || keycode == UP_ARROW_KEY)
	{
		ft_draw_wall(game, game->textures->north_texture);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->frame->pointer, x, y);
	}
	else if (keycode == A_KEY || keycode == LEFT_ARROW_KEY)
	{
		ft_draw_wall(game, game->textures->west_texture);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->frame->pointer, x, y);
	}
	else if (keycode == D_KEY || keycode == RIGHT_ARROW_KEY)
	{
		ft_draw_wall(game, game->textures->east_texture);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->frame->pointer, x, y);
	}
	else if (keycode == S_KEY || keycode == DOWN_ARROW_KEY)
	{
		ft_draw_wall(game, game->textures->south_texture);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->frame->pointer, x, y);
	}
	else if (keycode == ESC_KEY)
		ft_quit_window(game);
	return (0);
}