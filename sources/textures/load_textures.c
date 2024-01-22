/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:51:20 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/01/22 14:19:41 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_loading.h"
#include <fcntl.h>

static
int		ft_load_textures_and_map(t_game *game, char *map_path)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_load_elements(game, line))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int		ft_load_game(t_game *game, char *map_path)
{
	if (!ft_endswith(map_path, ".cub"))
		return (0);
	game->textures = ft_new_textures();
	if (!game->textures)
		return (0);
	if (!ft_load_textures_and_map(game, map_path))
	{
		free(game->textures);
		return (0);
	}
	return (1);
}
