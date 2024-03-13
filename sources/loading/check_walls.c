/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:10:41 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/07 17:25:08 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../libft/libft.h"

static
int	ft_has_west_wall(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			return (0);
		if (line[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

static
int	ft_has_east_wall(char *line)
{
	return (ft_endswith(line, "1"));
}

static
int	ft_has_north_wall(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			return (0);
		i++;
	}
	return (1);
}

static
int	ft_has_south_wall(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0')
			return (0);
		i++;
	}
	return (1);
}


int	ft_check_walls(t_game *game, size_t y)
{
	if (y == 0 && !ft_has_north_wall(game->textures->map[y]))
	{
		ft_printf("Crack in the north wall : '%s'", game->textures->map[y]);
        return (0);
	}
	if ((y == (game->textures->map_height - 1)) && !ft_has_south_wall(game->textures->map[y]))
	{
		ft_printf("Crack in the south wall : '%s'", game->textures->map[y]);
        return (0);
	}
	if (!ft_has_west_wall(game->textures->map[y]) || !ft_has_east_wall(game->textures->map[y]))
	{
		ft_printf("Crack in the east/west walls : '%s'", game->textures->map[y]);
        return (0);
	}
	return (1);
}
