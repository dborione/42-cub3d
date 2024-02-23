/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:52:46 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/02/23 15:46:56 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// fonction temporaire pour les testes
static
void	ft_draw_line(t_game *game, t_cub3d_images texture, int frame_i, int line)
{
	int wall_i;
	int	count;

	wall_i = texture.size_line * line;
	count = 0;
	while (wall_i < texture.size_line)
	{
		while (count < WIDTH / WALL_WIDTH)
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

	line = 0;
	frame_i = 0;
	while (line < WALL_HEIGHT)
	{
		count = 0;
		printf("LINE : %d\n", line);
		while (count < HEIGHT / WALL_HEIGHT)
		{
			ft_draw_line(game, texture, frame_i, line);
			count++;
			frame_i += game->textures->frame->size_line;
		}
		line++;
	}
}

void	ft_draw_wall(t_game *game)
{
	// int				i;
	//int				y;
	//int				pixels;
	t_cub3d_images	texture;

	// y = 0;
	// i = 0;
	texture.data = mlx_get_data_addr(game->textures->north_texture,
		&texture.bits_per_pixel, &texture.size_line, &texture.endian);
	printf("\nratio : %d, size_line : %d\n", WIDTH / 16, texture.size_line);
	printf("frame size_line : %d\n", game->textures->frame->size_line);
	//pixels = 0;
	// while (y < HEIGHT)
	// {
	// 	ft_draw_lines(game, texture, i);
	// 	i+=game->textures->frame->size_line * HEIGHT / WALL_HEIGHT * pixels;
	// 	pixels++;
	// 	y+=(HEIGHT / WALL_HEIGHT);
	// }
	ft_draw_lines(game, texture);
}