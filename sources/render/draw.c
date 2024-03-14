/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:39:46 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/14 13:52:16 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/cub3d_raycasting.h"
#include "../../includes/cub3d_render.h"

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

void	ft_draw_vertical_line(t_game *game, t_raycaster *raycaster, int x, t_wall_measures *wall_measures)
{
	t_cub3d_images	texture;
	// int				line;

	if (wall_measures)
		{

		}
	
	double			step = 1.0 * WALL_HEIGHT / raycaster->line->height;
	double			texture_position = (raycaster->line->bottom - WIN_HEIGHT / 2 + raycaster->line->height / 2) * step;
	//printf("texture position %f, %f\n", step, texture_position);
	texture.data = mlx_get_data_addr(ft_get_target(game, raycaster),
		&texture.bits_per_pixel, &texture.size_line, &texture.endian);
	//printf("top : %d, botton : %d\n", raycaster->line->top, raycaster->line->bottom);
	while (raycaster->line->bottom < raycaster->line->top)
	{
		int texY = (int)texture_position & (WALL_HEIGHT - 1);
        texture_position += step;
		double wallX; //where exactly the wall was hit
		if (raycaster->ray->side == NORTH_WALL && raycaster->ray->side == SOUTH_WALL)
			wallX = raycaster->player_pos_y + raycaster->ray->ray_to_wall_dist * raycaster->ray->delta_dist_y;
		else
			wallX = raycaster->player_pos_x + raycaster->ray->ray_to_wall_dist * raycaster->ray->delta_dist_x;
		wallX -= floor((wallX));

		//x coordinate on the texture
		int texX = (int)(wallX * (double)WALL_WIDTH);
		if ((raycaster->ray->side == NORTH_WALL && raycaster->ray->side == SOUTH_WALL) && raycaster->ray->dir_x > 0)
			texX = WALL_WIDTH - texX - 1;
		if ((raycaster->ray->side == WEST_WALL && raycaster->ray->side == EAST_WALL) && raycaster->ray->dir_y < 0)
			texX = WALL_WIDTH - texX - 1;
		game->textures->frame->data[raycaster->line->bottom * game->textures->frame->size_line + x*4] = texture.data[texX * 4 + texture.size_line  * texY];
		game->textures->frame->data[raycaster->line->bottom * game->textures->frame->size_line + x*4 + 1] = texture.data[texX * 4 + 1 + texture.size_line  * texY];
		game->textures->frame->data[raycaster->line->bottom * game->textures->frame->size_line + x*4 + 2] = texture.data[texX * 4 + 2 + texture.size_line  * texY];
		game->textures->frame->data[raycaster->line->bottom * game->textures->frame->size_line + x*4 + 3] = texture.data[texX * 4 + 3 + texture.size_line  * texY];
		raycaster->line->bottom++;
 	}
}
