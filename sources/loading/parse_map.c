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
int			ft_is_start_location(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

/*
		Le pitch est l'angle vertical, il va de :
		89 (haut) à -89 (bas) en passant par 0 (tout droit)

		le yaw est l'angle horizontal, il va de :
		-180 (demi-tour par la gauche, direction sud) à
		180 (demi-tour par la droite, direction sud) en
		passant par 0 (direction nord)
	*/

static
t_location	*ft_get_location(char direction, size_t x, size_t y)
{
	t_location *location;

	location = malloc(sizeof(t_location));
	if (!location)
		return (NULL);
	location->x = x * 3 - 1; /* *3 car on divise les sols en 9 cases */
	location->y = y * 3 - 1; /* -1 pour etre au milieu*/
	location->pitch = 0.0f;
	if (direction == 'N')
		location->yaw = 0.0f;
	else if (direction == 'W')
		location->yaw = -90.0f;
	else if (direction == 'E')
		location->yaw = 90.0f;
	else /* Direction sud */
		location->yaw = 180.0f;
	return (location);
}

static
int			ft_add_player_location(t_game *game, size_t x, size_t y)
{
	if (game->player)
		return (0);
	game->player = ft_get_location(game->textures->map[y][x], x, y);
	game->textures->map[y][x] = '0';
	if (!game->player)
		return (0);
	return (1);
}

static
int			ft_valid_map_element(char c)
{
	return (c == '0' || c == '0' || c == '1' || c == ' ' || ft_is_start_location(c));
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
		if (!ft_has_west_wall(game->textures->map[y]) || !ft_has_east_wall(game->textures->map[y]))
		{
				ft_printf("Crack in the walls : '%s'\n", game->textures->map[y]);
				return (0);
		}
		while (game->textures->map[y][x])
		{
			if (!ft_valid_map_element(game->textures->map[y][x]))
			{
				ft_printf("Invalide map element\n");
				return (0);
			}
			if (ft_is_start_location(game->textures->map[y][x]))
			{
				if (!ft_add_player_location(game, x, y))
					return (0);
			}
			x++;
		}
		y++;
	}
	if (!game->player)
		return (0);
	return (1);
}
