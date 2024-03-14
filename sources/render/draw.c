/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:39:46 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/14 17:10:43 by rbarbiot         ###   ########.fr       */
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

static
void    ft_get_wall_hit_point(t_game *game, t_raycaster *raycaster)
{
    raycaster->line->texture_map_pos = game->textures->map[(int)raycaster->player_pos_y][(int)raycaster->player_pos_x] - 1;
    raycaster->line->wall_hit_x = 0;
    if (raycaster->ray->side == EAST_WALL || raycaster->ray->side == WEST_WALL)
        raycaster->line->wall_hit_x = raycaster->player_pos_y +
            raycaster->ray->ray_to_wall_dist * raycaster->ray->dir_y;
    else
        raycaster->line->wall_hit_x = raycaster->player_pos_x +
            raycaster->ray->ray_to_wall_dist * raycaster->ray->dir_x;
    raycaster->line->wall_hit_x -= floor(raycaster->line->wall_hit_x); // double floor(double x) = returns the largest integer value less than or equal to x
}

void	ft_draw_vertical_line(t_game *game, t_raycaster *raycaster, int x)
{
	t_cub3d_images	texture;
	double			step = 1.0 * WALL_HEIGHT / raycaster->line->height;
	double			texture_position = (raycaster->line->bottom - WIN_HEIGHT / 2 + raycaster->line->height / 2) * step;
	//printf("texture position %f, %f\n", step, texture_position);
	texture.data = mlx_get_data_addr(ft_get_target(game, raycaster),
		&texture.bits_per_pixel, &texture.size_line, &texture.endian);
	while (raycaster->line->bottom < raycaster->line->top)
	{
		int texY = (int)texture_position & (WALL_HEIGHT - 1);
        texture_position += step;
		 //where exactly the wall was hit
		ft_get_wall_hit_point(game, raycaster);
		int texX = (int)(raycaster->line->wall_hit_x * (double)WALL_WIDTH);
		if ((raycaster->ray->side == NORTH_WALL || raycaster->ray->side == SOUTH_WALL) && raycaster->ray->dir_x > 0)
			texX = WALL_WIDTH - texX - 1;
		if ((raycaster->ray->side == WEST_WALL || raycaster->ray->side == EAST_WALL) && raycaster->ray->dir_y < 0)
			texX = WALL_WIDTH - texX - 1;
		game->textures->frame->data[raycaster->line->bottom * game->textures->frame->size_line + x * 4] = texture.data[texX * 4 + texture.size_line * texY];
		game->textures->frame->data[raycaster->line->bottom * game->textures->frame->size_line + x * 4 + 1] = texture.data[texX * 4 + 1 + texture.size_line * texY];
		game->textures->frame->data[raycaster->line->bottom * game->textures->frame->size_line + x * 4 + 2] = texture.data[texX * 4 + 2 + texture.size_line * texY];
		game->textures->frame->data[raycaster->line->bottom * game->textures->frame->size_line + x * 4 + 3] = texture.data[texX * 4 + 3 + texture.size_line * texY];
		raycaster->line->bottom++;
 	}
}
