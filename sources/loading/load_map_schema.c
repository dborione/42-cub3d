/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_schema.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:33:07 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/15 18:35:54 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/cub3d.h"

static
int	ft_empty_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

static
char	*ft_skip_empty_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (!ft_empty_line(line))
			return (line);
		free(line);
		line = get_next_line(fd);
	}
	return (NULL);
}

static
size_t	ft_line_size(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

static
int	ft_add_line(t_game *game, char **lines, char *line)
{
	char	*trimed_line;
	size_t	line_size;

	trimed_line = ft_strtrim_end(line, " \t\r\v");
	free(line);
	if (!trimed_line)
		return (0);
	line_size = ft_line_size(trimed_line);
	if (line_size > game->textures->map_width)
		game->textures->map_width = line_size;
	*lines = ft_cleanjoin(*lines, trimed_line);
	free(trimed_line);
	return (1);
}

void	ft_load_map_schema(t_game *game, int fd)
{
	char	*line;
	char	*lines;

	lines = NULL;
	line = ft_skip_empty_lines(fd);
	while (line)
	{
		game->textures->map_height++;
		if (ft_empty_line(line))
		{
			free(line);
			free(lines);
			return ;
		}
		if (!ft_add_line(game, &lines, line))
			return ;
		line = get_next_line(fd);
	}
	game->textures->map = ft_split(lines, '\n');
	free(lines);
}
