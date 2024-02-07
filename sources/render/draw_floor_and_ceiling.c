/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_and_ceiling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:00:21 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/02/06 15:36:39 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include <stdio.h>

void	ft_draw_ceiling(t_game *game, t_cub3d_images *frame)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	ft_printf("size_line %d\n", frame->size_line);
	while (y < 580)
	{
		x = 0;
		while (x < frame->size_line)
		{
			frame->data[i] = game->textures->ceiling->blue;
			frame->data[i + 1] = game->textures->ceiling->green;
			frame->data[i + 2] = game->textures->ceiling->red;
			frame->data[i + 3] = game->textures->ceiling->alpha;
			i+=4;
			x+=4;
		}
		y++;
	}
	ft_printf("first bit : %d\n", frame->data[0]);
}

void	ft_draw_floor(t_game *game, t_cub3d_images *frame)
{
	int	i;
	int	x;
	int	y;

	y = 580;
	i = frame->size_line * y;
	while (y < 1080)
	{
		x = 0;
		while (x < frame->size_line)
		{
			frame->data[i] = game->textures->floor->blue;
			frame->data[i + 1] = game->textures->floor->green;
			frame->data[i + 2] = game->textures->floor->red;
			frame->data[i + 3] = game->textures->floor->alpha;
			i+=4;
			x+=4;
		}
		y++;
	}



		/* Je fais jute des tests ici*/

	// int *buffer = (int *)mlx_get_data_addr(frame->data, &frame->bits_per_pixel, &frame->size_line, &frame->endian);
	// frame->size_line /= 4;

	// int color = 0xABCDEF;

	// // for(int y = 0; y < 1080; ++y)
	// // for(int x = 0; x < frame->size_line; ++x)
	// // {
	// // 	buffer[(y * frame->size_line) + x] = color;
	// // }

	// int	x;
	// int	y;

	// y = 0;
	// while (y < WIDTH)
	// {
	// 	x = 0;
	// 	while (x < HEIGHT)
	// 	{
	// 		// printf("%p\n", &buffer[0]);
	// 		buffer[y * WIDTH + x] = color;
	// 		// printf("jfkdl\n");
	// 		x++;
	// 	}
	// 	y++;
	// }
	// //mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->canvas.img, 0, 0);
	// if (game) {};
	// if (buffer) {};
	// if (color) {};
}
