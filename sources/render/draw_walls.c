/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:52:46 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/02/28 17:03:09 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// fonction temporaire pour les testes
static
void	ft_draw_line(
	t_game *game, t_cub3d_images texture, int frame_i, int line)
{
	int wall_i;
	int	count;
	int	factor;
	int	end;

	wall_i = texture.size_line * line;
	count = 0;
	factor = DISTANCE_FOR_FULL_WALL / game->distance * (WIDTH / WALL_WIDTH);
	end = texture.size_line * (line + 1);
	while (wall_i < end)
	/*
		ajouter une protection évitant de dépasser de l'écran
	*/
	{
		while (count < factor)
		{
			game->textures->frame->data[frame_i] = texture.data[wall_i];
			game->textures->frame->data[frame_i + 1] = texture.data[wall_i + 1];
			game->textures->frame->data[frame_i + 2] = texture.data[wall_i + 2];
			game->textures->frame->data[frame_i + 3] = texture.data[wall_i + 3];
			frame_i+=4;
			count++;
		}
		count = 0;
		wall_i+=4;
	}
}

static
void	ft_draw_lines(t_game *game, t_cub3d_images texture)
{
	int	line;
	int	count;
	int frame_i;
	int	factor;

	line = 0;
	frame_i = 0;
	factor = DISTANCE_FOR_FULL_WALL / game->distance * (HEIGHT / WALL_HEIGHT);
	while (line < WALL_HEIGHT && line < HEIGHT)
	{
		count = 0;
		while (count < factor)
		{
			ft_draw_line(game, texture, frame_i, line);
			frame_i += game->textures->frame->size_line;
			count++;
		}
		line++;
	}
}

void	ft_draw_wall(t_game *game)
{
	t_cub3d_images	texture;

	texture.data = mlx_get_data_addr(game->textures->north_texture,
		&texture.bits_per_pixel, &texture.size_line, &texture.endian);
	game->distance = 6.7625;
	ft_draw_lines(game, texture);
}
