/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_schema.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:33:07 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/01/23 11:09:25 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/cub3d.h"

static
int		ft_empty_line(char *line)
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
char		*ft_skip_empty_lines(int fd)
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

void	ft_load_map_schema(t_game *game, int fd)
{
	char	*line;
	char	*lines;

	
	lines = NULL;
	line = ft_skip_empty_lines(fd);
	while (line)
	{
		//ft_printf("Read map line : %s", line);
		if (ft_empty_line(line))
		{
			free(line);
			free(lines);
			ft_printf("Error empty line in map");
			return ;
		}
		lines = ft_cleanjoin(lines, line);
		free(line);
		line = get_next_line(fd);
	}
	game->textures->map = ft_split(lines, '\n');
	free(lines);
}
