/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:37:43 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/02/05 14:53:28 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../includes/cub3d.h"
#include "../../includes/cub3d_loading.h"
#include "../../libft/libft.h"
#include <stdio.h>

static
int	ft_get_pixel(t_cub3d_images wall, int start)
{
	t_rgb	rgb;
	int		i;
	char	count;

	i = start;
	count = 0;
	ft_printf("start : %d\n", start);
	while (count < 4)
	{
		if (count == 0)
			rgb.blue = (unsigned char)wall.data[i];
		else if (count == 1)
			rgb.green = (unsigned char)wall.data[i];
		else if (count == 2)
			rgb.red = (unsigned char)wall.data[i];
		else if (count == 3)
			rgb.alpha = (unsigned char)wall.data[i];
		i++;
		count++;
	}
	return (ft_get_int_rgb(&rgb));
}

void	ft_render_wall(t_game *game, float base_x, float base_y)
{
	double			distance;
	t_location		pen_location;
	t_cub3d_images	wall;
	int				i;

	wall.data = mlx_get_data_addr(game->textures->north_texture,
		&wall.bits_per_pixel, &wall.size_line, &wall.endian);

	// changer game->start par le joueur plus tard 
	printf("start : x %f, y %f\n", game->start->x, game->start->y);
	printf("base : x %f, y %f\n", base_x, base_y);
	printf("wall data : bpp %d, size_line %d, enfian %d\n",
		wall.bits_per_pixel, wall.size_line, wall.endian);
	distance = sqrt(pow(base_x - game->start->x, 2)
		+ pow(base_y - game->start->y, 2));

	printf("Distance : %f\n", distance);
	printf("Line : %d\n", wall.size_line / 4);
	pen_location.y = 0; // faire des verifs si paire / impaire, 240
	i = 0;
	while (pen_location.y < 480)
	{
		pen_location.x = 0;
		i = 0; // à corriger
		while (i < wall.size_line / 4)
		{
			int rgb_color = ft_get_pixel(wall, i);
			printf("rgb color: %d\n", rgb_color);
			//printf("x loop coo: x %d, y %d\n", (int)pen_location.x, (int)pen_location.y);
			mlx_pixel_put(game->mlx, game->mlx_win, (int)pen_location.y, (int)pen_location.x, rgb_color);
			pen_location.x++;
			i += 4; //distance;
		}
		pen_location.y++;// =distance;
		//i += distance * 4;
		//printf("y loop coo: x %d, y %d\n", (int)pen_location.x, (int)pen_location.y);
	}
	ft_printf("exit :p !\n");
}