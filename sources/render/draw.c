/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:39:46 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/08 01:46:18 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/cub3d_raycasting.h"

// void ft_draw_frame(t_game *game)
// {
// 	t_cub3d_images	frame;
// 	t_location		pen_location;
// 	int				i;

// 	frame.data = mlx_get_data_addr(game->textures->test,
// 		&frame.bits_per_pixel, &frame.size_line, &frame.endian);

// 	pen_location.y = 0;
// 	i = 0;
// 	while (frame.data[i] && pen_location.y < WIN_HEIGHT)
// 	{
// 		pen_location.x = 0;
// 		while (pen_location.x < frame.size_line)
// 		{
// 			int rgb_color = 0;
// 			frame.data[i] = rgb_color;
// 			pen_location.x++;
// 			i++;
// 		}
// 		pen_location.y++;
// 	}
// 	mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->test, 0, 0);
// }

void ft_draw_vertical_line(t_game *game, t_raycaster *raycaster, int x) // ajouter le target ici
{
	t_cub3d_images	texture;
	void			*target;
	int				factor;
	int				count;
	int				line;
	int				remainder;

	if (raycaster->ray->side == NORTH_WALL)
		target = game->textures->north_texture;
	else if (raycaster->ray->side == WEST_WALL)
		target = game->textures->west_texture;
	else if (raycaster->ray->side == EAST_WALL)
		target = game->textures->east_texture;
	else
		target = game->textures->south_texture;
	texture.data = mlx_get_data_addr(target,
		&texture.bits_per_pixel, &texture.size_line, &texture.endian);
	/*
		colomn_size pourra etre retiré car on ne l'utilise qu'une seule fois
		mais je la garde pour le moment pour avoir un
	*/
	factor = raycaster->line->height / WALL_HEIGHT;
	remainder = raycaster->line->height % WALL_HEIGHT;
	// ft_printf("factor : top %d - bottom : %d / wall %d = %d, rest : %d, Height : %d\n",
	// 	raycaster->line->top, raycaster->line->bottom, WALL_HEIGHT, factor, remainder, raycaster->line->height);
	line = 0;
	count = 0;
	while (count < raycaster->line->height - (raycaster->line->top - raycaster->line->bottom))
		count++;
	if (count)
		count /= 2;
	while (count && count - factor > 0)
	{
		line++;
		count -= factor;
	}
	while (raycaster->line->bottom < raycaster->line->top && line < WALL_HEIGHT)
	{
		//if (line && rest && line % rest)
		if (line > WALL_HEIGHT - remainder || line < remainder)
		{
			//while (rest)
			{
				game->textures->frame->data[raycaster->line->bottom * game->textures->frame->size_line + x*4] = texture.data[0 + texture.size_line  * line];
				game->textures->frame->data[raycaster->line->bottom * game->textures->frame->size_line + x*4 + 1] = texture.data[1 + texture.size_line  * line];
				game->textures->frame->data[raycaster->line->bottom * game->textures->frame->size_line + x*4 + 2] = texture.data[2 + texture.size_line  * line];
				game->textures->frame->data[raycaster->line->bottom * game->textures->frame->size_line + x*4 + 3] = texture.data[3 + texture.size_line  * line];
				raycaster->line->bottom++;
				remainder--;
			}
		}
		while (count < factor && raycaster->line->bottom < raycaster->line->top)// faire attention aux facteurs negatifs
		{
			game->textures->frame->data[raycaster->line->bottom * game->textures->frame->size_line + x*4] = texture.data[0 + texture.size_line  * line];
			game->textures->frame->data[raycaster->line->bottom * game->textures->frame->size_line + x*4 + 1] = texture.data[1 + texture.size_line  * line];
			game->textures->frame->data[raycaster->line->bottom * game->textures->frame->size_line + x*4 + 2] = texture.data[2 + texture.size_line  * line];
			game->textures->frame->data[raycaster->line->bottom * game->textures->frame->size_line + x*4 + 3] = texture.data[3 + texture.size_line  * line];
			raycaster->line->bottom++;
			count++;
		}
		line++;
		count = 0;
 	}
}