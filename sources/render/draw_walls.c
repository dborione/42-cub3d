/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:52:46 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/02/23 13:29:36 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// fonction temporaire pour les testes
void	ft_draw_wall(t_game *game)
{
	int				i;
	int				x;
	int				y;
	int				pixel;
	t_cub3d_images	texture;

	y = 10;
	i = game->textures->frame->size_line * y;
	pixel = 0;
	texture.data = mlx_get_data_addr(game->textures->north_texture,
		&texture.bits_per_pixel, &texture.size_line, &texture.endian);

	int tmp_buffer = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < texture.size_line)
		{
			game->textures->frame->data[i] = texture.data[pixel];
			game->textures->frame->data[i + 1] = texture.data[pixel + 1];
			game->textures->frame->data[i + 2] = texture.data[pixel + 2];
			game->textures->frame->data[i + 3] = texture.data[pixel + 3];
			i+=4;
			x+=4;
			tmp_buffer++;
			if (tmp_buffer > HEIGHT / 16)
			{
				pixel+=4;
				tmp_buffer = 0;
			}
		}
		y++;
	}
}