/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_corridor_walls.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:02:30 by dborione          #+#    #+#             */
/*   Updated: 2024/03/13 15:02:32 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../../includes/cub3d_loading.h"
#include "../libft/libft.h"

static
int	ft_has_east_corridor_wall(char *line)
{
	size_t	i;
	size_t	len;

	i = 1;
	len = ft_strlen(line);
	while (i < len)
	{
		if ((line[i] == '0' || ft_is_start_location(line[i]))
			&& line[i + 1] == ' ')
			return (0);
		i++;
	}
	return (1);
}

static
int	ft_has_west_corridor_wall(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			break ;
		i++;
	}
	while (line[i] == ' ')
		i++;
	if (line[i] == '0' || ft_is_start_location(line[i]))
		return (0);
	return (1);
}

static
int	ft_has_north_corridor_wall(char *previous_line, char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' && previous_line[i] == '0')
			return (0);
		i++;
	}
	return (1);
}

static
int	ft_has_south_corridor_wall(char *previous_line, char *line)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(previous_line);
	while (line[i])
	{
		if ((line[i] == '0' || ft_is_start_location(line[i]))
			&& i >= len)
			return (0);
		if ((line[i] == '0' || ft_is_start_location(line[i]))
			&& previous_line[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_corridor_walls(t_game *game, size_t y)
{
	if (!ft_has_east_corridor_wall(game->textures->map[y])
		|| !ft_has_west_corridor_wall(game->textures->map[y]))
	{
		ft_printf("Crack in the west/east corridor walls : '%s'\n",
			game->textures->map[y]);
		return (0);
	}
	if (y >= 1 && (!ft_has_north_corridor_wall(game->textures->map[y - 1],
				game->textures->map[y])
			|| !ft_has_south_corridor_wall(game->textures->map[y - 1],
				game->textures->map[y])))
	{
		ft_printf("Crack in the north/south corridor walls : '%s'\n",
			game->textures->map[y]);
		return (0);
	}
	return (1);
}
