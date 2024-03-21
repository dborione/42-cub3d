/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:51:20 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/15 18:17:03 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_loading.h"
#include "../../includes/cub3d_textures.h"
#include <fcntl.h>

static
int	ft_new_textures(t_game *game)
{
	game->textures = malloc(sizeof(t_cub3d_textures));
	if (!game->textures)
		return (0);
	game->textures->ceiling = NULL;
	game->textures->floor = NULL;
	game->textures->north_texture = NULL;
	game->textures->south_texture = NULL;
	game->textures->west_texture = NULL;
	game->textures->east_texture = NULL;
	game->textures->map = NULL;
	game->textures->map_width = 0;
	game->textures->map_height = 0;
	game->textures->frame = malloc(sizeof(t_cub3d_images));
	if (!game->textures->frame)
		return (0);
	game->textures->frame->pointer = mlx_new_image(game->mlx,
			WIN_WIDTH, WIN_WIDTH);
	game->textures->frame->data
		= mlx_get_data_addr(game->textures->frame->pointer,
			&(game->textures->frame)->bits_per_pixel,
			&(game->textures->frame)->size_line,
			&(game->textures->frame)->endian);
	return (1);
}

static
int	ft_elements_loaded(t_game *game)
{
	if (!game->textures)
		return (0);
	if (game->textures->ceiling == NULL)
		return (0);
	if (game->textures->floor == NULL)
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
int	ft_load_textures(t_game *game, char *map_path)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_load_element(game, line))
		{
			free(line);
			close(fd);
			return (0);
		}
		free(line);
		if (ft_elements_loaded(game))
		{
			ft_load_map_schema(game, fd);
			break ;
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	ft_load_game(t_game *game, char *map_path)
{
	if (!ft_endswith(map_path, ".cub"))
		return (0);
	if (!ft_new_textures(game))
		return (0);
	if (!ft_load_textures(game, map_path))
	{
		ft_unload_game(game);
		return (0);
	}
	if (!ft_parse_map(game))
	{
		ft_unload_game(game);
		return (0);
	}
	return (1);
}
