/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:14:06 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/02/05 15:38:52 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/cub3d_render.h"

int	ft_key_hook(int keycode, t_game *game)
{
	int	x;
	int	y;
	int	color;

	if (keycode == 15)
		color = 0x00FF0000;
	else if (keycode == 5)
		color = 0x0000FF00;
	else if (keycode == 11)
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