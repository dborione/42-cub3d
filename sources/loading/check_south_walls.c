/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_south_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:16:41 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/19 14:53:24 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_loading.h"
#include "../libft/libft.h"

static
size_t	ft_init(
		t_game *game, size_t *x, size_t *read_width, size_t *last_line_len)
{
	*x = 0;
	*read_width = 0;
	*last_line_len = 0;
	return (game->textures->map_height - 1);
}

static
int	ft_targeted_wall(char **map, size_t x, size_t y)
{
	size_t	i;

	i = 0;
	if (y < 2)
		return (0);
	y--;
	while (y > 0 && map[y] && map[y][i])
	{
		while (map[y][i] && i < x)
			i++;
		if (i == x)
		{
			if (map[y][i] == '0' || ft_is_start_location(map[y][i]))
				return (0);
			else if (map[y][i] == '1')
				return (1);
		}
		y--;
		i = 0;
	}
	return (0);
}

static
int	ft_get_target_line(
	t_game *game, size_t x, size_t *y, size_t last_line_len)
{
	if (!game->textures->map[*y][x] && x < game->textures->map_width)
	{
		if (*y == 0)
			return (0);
		while (y > 0 && ft_strlen(game->textures->map[*y]) <= last_line_len)
			(*y)--;
	}
	return (1);
}

int	ft_has_south_wall(t_game *game)
{
	size_t	x;
	size_t	y;
	size_t	read_width;
	size_t	last_line_len;

	y = ft_init(game, &x, &read_width, &last_line_len);
	while (game->textures->map[y][x] && read_width < game->textures->map_width)
	{
		last_line_len++;
		if (game->textures->map[y][x] == '0'
			|| ft_is_start_location(game->textures->map[y][x]))
			return (0);
		if (game->textures->map[y][x] == ' ')
		{
			if (!ft_targeted_wall(game->textures->map, x, y))
				return (0);
			read_width++;
		}
		else if (game->textures->map[y][x] == '1')
			read_width++;
		x++;
		if (!ft_get_target_line(game, x, &y, last_line_len))
			return (0);
	}
	return (read_width == game->textures->map_width);
}
