/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_floor_and_ceiling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:00:21 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/01/31 19:35:06 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_load_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < 550)
	{
		x = 0;
		while (x < 1920)
		{
			mlx_pixel_put(game->mlx, game->mlx_win, x, y, game->textures->ceiling);
			x++;
		}
		y++;
	}
}

void	ft_load_floor(t_game *game)
{
	int	x;
	int	y;

	y = 550;
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			mlx_pixel_put(game->mlx, game->mlx_win, x, y, game->textures->floor);
			x++;
		}
		y++;
	}
}
