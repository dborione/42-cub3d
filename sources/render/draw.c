/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:39:46 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/15 16:57:54 by rbarbiot         ###   ########.fr       */
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
void	ft_get_wall_hit_point(t_raycaster *raycaster)
{
	raycaster->line->wall_hit_x = 0;
	if (raycaster->ray->side == EAST_WALL
		|| raycaster->ray->side == WEST_WALL)
	{
		raycaster->line->wall_hit_x = raycaster->player_pos_y
			+ raycaster->ray->ray_to_wall_dist * raycaster->ray->dir_y;
	}
	else
	{
		raycaster->line->wall_hit_x = raycaster->player_pos_x
			+ raycaster->ray->ray_to_wall_dist * raycaster->ray->dir_x;
	}
	raycaster->line->wall_hit_x -= floor(raycaster->line->wall_hit_x);
}

static
void	ft_draw_pixel(
	t_game *game, t_cub3d_images texture, int frame_pixel, int texture_pixel)
{
	game->textures->frame->data[frame_pixel]
		= texture.data[texture_pixel];
	game->textures->frame->data[frame_pixel + 1]
		= texture.data[texture_pixel + 1];
	game->textures->frame->data[frame_pixel + 2]
		= texture.data[texture_pixel + 2];
	game->textures->frame->data[frame_pixel + 3]
		= texture.data[texture_pixel + 3];
}

static
int	ft_get_pixel_x(t_raycaster *raycaster)
{
	int	pixel_x;

	pixel_x = (int)(raycaster->line->wall_hit_x * (float)WALL_WIDTH);
	if ((raycaster->ray->side == WEST_WALL
			|| raycaster->ray->side == EAST_WALL) && raycaster->ray->dir_x < 0)
	{
		pixel_x = WALL_WIDTH - pixel_x - 1;
	}
	if ((raycaster->ray->side == NORTH_WALL
			|| raycaster->ray->side == SOUTH_WALL) && raycaster->ray->dir_y > 0)
	{
		pixel_x = WALL_WIDTH - pixel_x - 1;
	}
	return (pixel_x);
}

void	ft_draw_vertical_line(t_game *game, t_raycaster *raycaster, int x)
{
	t_cub3d_images	texture;
	float			step;
	float			texture_position;
	int				pixel_x;
	int				pixel_y;

	texture.data = mlx_get_data_addr(ft_get_target(game, raycaster),
			&texture.bits_per_pixel, &texture.size_line, &texture.endian);
	ft_get_wall_hit_point(raycaster);
	pixel_x = ft_get_pixel_x(raycaster);
	step = 1.0 * WALL_HEIGHT / raycaster->line->height;
	texture_position = (raycaster->line->bottom - WIN_HEIGHT
			/ 2 + raycaster->line->height / 2) * step;
	while (raycaster->line->bottom < raycaster->line->top)
	{
		pixel_y = (int)texture_position & (WALL_HEIGHT - 1);
		texture_position += step;
		ft_draw_pixel(game, texture,
			raycaster->line->bottom * game->textures->frame->size_line + x * 4,
			pixel_x * 4 + texture.size_line * pixel_y);
		raycaster->line->bottom++;
	}
}
