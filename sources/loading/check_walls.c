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
int	ft_has_east_corridor_wall(char *line)
{
	size_t	i;
	size_t	len;

	i = 1;
	len = ft_strlen(line);
	while (i < len)
	{
		if (line[i] == '0' && line[i + 1] == ' ')
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
	if (line[i] == '0')
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
		if (line[i] == '0' && i >= len)
			return (0);
		if (line[i] == '0' && previous_line[i] == ' ')
			return (0);
		i++;
	}
	return (1);
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

int	ft_check_walls(t_game *game, size_t y)
{
	if (y == 0 && !ft_has_north_wall(game->textures->map[y]))
	{
		ft_printf("Crack in the north wall : '%s'\n", game->textures->map[y]);
		return (0);
	}
	if (!ft_has_west_wall(game->textures->map[y]) || !ft_has_east_wall(game->textures->map[y]))
	{
		ft_printf("Crack in the east/west walls : '%s'\n", game->textures->map[y]);
		return (0);
	}
	if (!ft_has_east_corridor_wall(game->textures->map[y]) || !ft_has_west_corridor_wall(game->textures->map[y]))
	{
		ft_printf("Crack in the east/west corridor walls : '%s'\n", game->textures->map[y]);
		return (0);
	}
	if (y >= 1 && (!ft_has_north_corridor_wall(game->textures->map[y - 1], game->textures->map[y])
		|| !ft_has_south_corridor_wall(game->textures->map[y - 1], game->textures->map[y])))
	{
		ft_printf("Crack in the north/south corridor walls : '%s'\n", game->textures->map[y]);
		return (0);
	}
	return (1);
}
