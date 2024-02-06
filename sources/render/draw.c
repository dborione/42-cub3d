/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:39:46 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/02/06 12:12:07 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/cub3d.h"

void ft_draw_frame(t_game *game)
{
	t_cub3d_images	frame;
	t_location		pen_location;
	int				i;

	frame.data = mlx_get_data_addr(game->textures->test,
		&frame.bits_per_pixel, &frame.size_line, &frame.endian);

	pen_location.y = 0;
	i = 0;
	while (frame.data[i] && pen_location.y < HEIGHT)
	{
		pen_location.x = 0;
		while (pen_location.x < frame.size_line)
		{
			int rgb_color = 0;
			frame.data[i] = rgb_color;
			pen_location.x++;
			i++;
		}
		pen_location.y++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->test, 0, 0);
}
