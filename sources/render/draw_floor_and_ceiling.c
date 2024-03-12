/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_and_ceiling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:00:21 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/07 15:01:36 by rbarbiot         ###   ########.fr       */
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
	end =  WIN_HEIGHT / 2;
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
}

void	ft_draw_floor(t_game *game)
{
	int	i;
	int	x;
	int	y;

	y =  WIN_HEIGHT / 2;
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
