/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_location.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:26:18 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/02/19 14:30:31 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static
int	ft_is_start_location(char c)
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
	location->x = x;
	location->y = y;
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

int	ft_load_player_location(t_game *game)
{
	size_t	x;
	size_t	y;

	if (!game->textures || !game->textures->map)
		return (0);
	y = 0;
	while (game->textures->map[y])
	{
		x = 0;
		while (game->textures->map[y][x])
		{
			if (ft_is_start_location(game->textures->map[y][x]))
			{
				if (game->player)
					return (0);
				game->textures->map[y][x] = '0'; 
				/*
					pour ne plus devoir verifier si c'est un mur
					ça facilitera le travail pour plus tard dans le code
				*/
				game->player = ft_get_location(game->textures->map[y][x], x, y);
				if (!game->player)
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
