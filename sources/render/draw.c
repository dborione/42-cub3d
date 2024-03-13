/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:39:46 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/13 11:57:21 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/cub3d_raycasting.h"

static
void	*ft_get_target(t_game *game, t_raycaster *raycaster)
{
	if (raycaster->ray->side == NORTH_WALL)
		return (game->textures->north_texture);
	else if (raycaster->ray->side == WEST_WALL)
		return (game->textures->west_texture);
	else if (raycaster->ray->side == EAST_WALL)
		return (game->textures->east_texture);
	return (game->textures->south_texture);
}

void ft_draw_vertical_line(t_game *game, t_raycaster *raycaster, int x) // ajouter le target ici
{
	t_cub3d_images	texture;
	int				factor;
	int				count;
	int				line;
	int				remainder;

	texture.data = mlx_get_data_addr(ft_get_target(game, raycaster),
		&texture.bits_per_pixel, &texture.size_line, &texture.endian);
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
