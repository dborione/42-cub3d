/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_and_ceiling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:00:21 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/05 19:22:19 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"

void	ft_draw_ceiling(t_game *game)
{
	int	i;
	int	x;
	int	y;
	int	end;

	i = 0;
	y = 0;
	//ft_printf("size_line %d\n", game->textures->frame->size_line);
	end =  WIN_HEIGHT / 10 * 6;
	while (y < end)
	{
		x = 0;
		while (x < game->textures->frame->size_line)
		{
			game->textures->frame->data[i] = game->textures->ceiling->blue;
			game->textures->frame->data[i + 1] = game->textures->ceiling->green;
			game->textures->frame->data[i + 2] = game->textures->ceiling->red;
			game->textures->frame->data[i + 3] = game->textures->ceiling->alpha;
			i+=4;
			x+=4;
		}
		y++;
	}
	ft_printf("first bit : %d\n", game->textures->frame->data[0]);
}

void	ft_draw_floor(t_game *game)
{
	int	i;
	int	x;
	int	y;

	y =  WIN_HEIGHT / 10 * 6;
	i = game->textures->frame->size_line * y;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < game->textures->frame->size_line)
		{
			game->textures->frame->data[i] = game->textures->floor->blue;
			game->textures->frame->data[i + 1] = game->textures->floor->green;
			game->textures->frame->data[i + 2] = game->textures->floor->red;
			game->textures->frame->data[i + 3] = game->textures->floor->alpha;
			i+=4;
			x+=4;
		}
		y++;
	}
}
