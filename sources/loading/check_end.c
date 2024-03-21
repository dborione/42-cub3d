/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:18:00 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/19 14:09:11 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../libft/libft.h"

int	ft_corridord_has_end(t_game *game, size_t x, size_t y)
{
	y++;
	while (game->textures->map[y])
	{
		if (ft_strlen(game->textures->map[y]) <= x)
			return (0);
		if (game->textures->map[y][x] == ' ')
			return (0);
		if (game->textures->map[y][x] == '1')
			return (1);
		y++;
	}
	return (0);
}
