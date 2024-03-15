/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:51:20 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/05 14:23:41 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_loading.h"
#include "../../includes/cub3d_textures.h"
#include <stdlib.h> //check
#include <fcntl.h> //check

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
	textures->map_width = 0;
	textures->map_height = 0;
	textures->frame = malloc(sizeof(t_cub3d_images));
	if (!textures->frame)
	{
		free(textures);
		return (NULL);
	}
	return (textures);
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
	int	fd;
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
	int	width;
	int	height;

	if (!ft_endswith(map_path, ".cub"))
		return (0);
	game->textures = ft_new_textures();
	if (!game->textures)
		return (0);
	width = WIN_WIDTH;
	height = WIN_HEIGHT;
	game->textures->frame->pointer = mlx_new_image(game->mlx, width, height); // ajouter une protection
	game->textures->frame->data = mlx_get_data_addr(game->textures->frame->pointer,
		&(game->textures->frame)->bits_per_pixel, &(game->textures->frame)->size_line, &(game->textures->frame)->endian);
	ft_printf("Textures initialized\n");
	if (!ft_load_textures(game, map_path)) //leak
	{
		ft_unload_game(game); //leak
		return (0);
	}
	ft_printf("Textures loaded\n");
	if (!ft_parse_map(game))
	{
		ft_unload_game(game);
		return (0);
	}
	return (1);
}
