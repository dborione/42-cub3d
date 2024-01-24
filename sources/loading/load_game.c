/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:51:20 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/01/23 12:29:01 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_loading.h"
#include "../../includes/cub3d_textures.h"
#include <stdlib.h>
#include <fcntl.h>

static
int					ft_elements_loaded(t_game *game)
{
	if (!game->textures)
		return (0);
	if (!game->textures->ceiling)
		return (0);
	if (!game->textures->floor)
		return (0);
	if (!game->textures->north_texture)
		return (0);
	if (!game->textures->south_texture)
		return (0);
	if (!game->textures->east_texture)
		return (0);
	if (!game->textures->west_texture)
		return (0);
	return (1);
}

static
int					ft_load_textures(t_game *game, char *map_path)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		ft_printf("Read line : %s", line);
		if (!ft_load_element(game, line))
		{
			free(line);
			return (0);
		}
		free(line);
		if (ft_elements_loaded(game))
		{
		ft_printf("Lets load map schema\n");
			ft_load_map_schema(game, fd);
			break ;
		}
		line = get_next_line(fd);
	}
	return (1);
}

static
t_cub3d_textures	*ft_new_textures(void)
{
	t_cub3d_textures	*textures;

	textures = malloc(sizeof(t_cub3d_textures));
	if (!textures)
		return (NULL);
	textures->ceiling = NULL;
	textures->floor = NULL;
	textures->north_texture = NULL;
	textures->south_texture = NULL;
	textures->west_texture = NULL;
	textures->east_texture = NULL;
	textures->map = NULL;
	return (textures);
}

int					ft_load_game(t_game *game, char *map_path)
{
	if (!ft_endswith(map_path, ".cub"))
		return (0);
	game->textures = ft_new_textures();
	if (!game->textures)
		return (0);
	ft_printf("Textures initialized\n");
	if (!ft_load_textures(game, map_path))
	{
		ft_unload_game(game);
		return (0);
	}
	if (!ft_load_player_location(game))
		return (0);
	/* Charger les premieres images du jeu ici */
	return (1);
}