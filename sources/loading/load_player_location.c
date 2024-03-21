/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_location.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:25:11 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/15 16:27:52 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_is_start_location(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

static
t_location	*ft_get_location(char direction, size_t x, size_t y)
{
	t_location	*location;

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
	else
		location->yaw = 180.0f;
	return (location);
}

int	ft_add_player_location(t_game *game, size_t x, size_t y)
{
	if (game->player)
		return (0);
	game->player = ft_get_location(game->textures->map[y][x], x, y);
	game->textures->map[y][x] = '0';
	if (!game->player)
		return (0);
	return (1);
}
