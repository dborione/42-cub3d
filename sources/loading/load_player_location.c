/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_location.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:25:11 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/01 13:30:31 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdio.h>

/*
		Le pitch est l'angle vertical, il va de :
		89 (haut) à -89 (bas) en passant par 0 (tout droit)

		le yaw est l'angle horizontal, il va de :
		-180 (demi-tour par la gauche, direction sud) à
		180 (demi-tour par la droite, direction sud) en
		passant par 0 (direction nord)
	*/

// static
// void		ft_set_position(
// 	t_game *game, t_location *location, size_t x, size_t y)
// {
// 	location->x = x - (game->textures->map_width
// 		+ game->textures->map_width % 2) / 2;
// 	location->y = y - (game->textures->map_height
// 		+ game->textures->map_height % 2) / 2;
// 	location->x *= 3;
// 	location->y *= 3;
// 	if (location->x < 0)
// 		location->x++;
// 	else
// 		location->x--;
// 	if (location->y < 0)
// 		location->y++;
// 	else
// 		location->y--;
// }

static
t_location	*ft_get_location(
	t_game *game, char direction, size_t x, size_t y)
{
	t_location *location;

	location = malloc(sizeof(t_location));
	if (!location)
		return (NULL);
	//ft_set_position(game, location, x, y);
	location->pitch = 0.0f;
	if (direction == 'N')
		location->yaw = 0.0f;
	else if (direction == 'W')
		location->yaw = -90.0f;
	else if (direction == 'E')
		location->yaw = 90.0f;
	else /* Direction sud */
		location->yaw = 180.0f;
	if (x && y && game)
	{}
	return (location);
}

int			ft_add_player_location(t_game *game, size_t x, size_t y)
{
	if (game->player)
		return (0);
	game->player = ft_get_location(game,
		game->textures->map[y][x], x, y);
	// printf("Player location : x %f, y %f, pitch %f, yaw %f",
	// 	game->player->x, game->player->y, game->player->pitch, game->player->yaw);
	game->textures->map[y][x] = '0';
	if (!game->player)
		return (0);
	return (1);
}
