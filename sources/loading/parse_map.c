/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:26:18 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/02/28 17:01:41 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/cub3d_loading.h"

static
int			ft_valid_map_element(char c)
{
	return (c == '0' || c == '0' || c == '1' || c == ' ' || ft_is_start_location(c));
}

static
int	ft_check_elements_and_location(t_game *game, size_t x, size_t y)
{
	if (!ft_valid_map_element(game->textures->map[y][x]))
	{
		ft_printf("Invalid map element\n");
		return (0);
	}
	if (ft_is_start_location(game->textures->map[y][x]))
	{
		if (!ft_add_player_location_pars(game, x, y))
			return (0);
	}
	return (1);
}

int			ft_parse_map(t_game *game)
{
	size_t	x;
	size_t	y;

	if (!game->textures || !game->textures->map)
		return (0);
	y = 0;
	while (game->textures->map[y])
	{
		x = 0;
		if (!ft_check_walls(game, y))
			return (0);
		while (game->textures->map[y][x])
		{
			if	(!ft_check_elements_and_location(game, x, y))
				return (0);
			x++;
		}
		y++;
	}
	if (!game->player)
		return (0);
	return (1);
}
