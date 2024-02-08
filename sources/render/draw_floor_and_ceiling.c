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
}
