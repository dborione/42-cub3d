/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:11:14 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/01/22 22:59:43 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/cub3d_loading.h"

/* Verifie si la texture n'a pas déjà été chargée */
static
int		ft_texture_loaded(t_game *game, char target[3])
{
	if (ft_isequal(target, "NO"))
		return (game->textures->north_texture != NULL);
	if (ft_isequal(target, "SO"))
		return (game->textures->south_texture != NULL);
	if (ft_isequal(target, "WE"))
		return (game->textures->west_texture != NULL);
	if (ft_isequal(target, "EA"))
		return (game->textures->east_texture != NULL);
	return (0);
}

static
void	ft_set_texture(t_game *game, char target[3], void *texture)
{
	ft_printf("%s added\n", target);
	if (ft_isequal(target, "NO"))
		game->textures->north_texture = texture;
	else if (ft_isequal(target, "SO"))
		game->textures->south_texture = texture;
	else if (ft_isequal(target, "WE"))
		game->textures->west_texture = texture;
	else if (ft_isequal(target, "EA"))
		game->textures->east_texture = texture;
}
static
int		ft_load_texture(
	t_game *game, char *line, char target[3])
{
	int		i;
	void	*tmp;
	char	*file;
	int		width;
	int		height;

	if (ft_texture_loaded(game, target))
	{
		ft_printf("Texture %s already loaded\n", target);
		return (0);
	}

	if (!line[2])
		return (0);
	i = 2;
	while (ft_isspace(line[i]))
		i++;
	if (!line[i])
		return (0);
	tmp = NULL;
	width = WALL_WIDTH;
	height = WALL_HEIGHT;
	/* if (ft_endswith(&line[i], "png"))
	tmp = mlx_png_file_to_image(game->mlx, &line[i], &width, &height) else */
	file = ft_strtrim(&line[i], "\n");
	if (!file)
		return (0);
	if (ft_endswith(file, ".xpm"))
	{
		ft_printf("%s loading file : '%s'\n", target, file);
		tmp = mlx_xpm_file_to_image(game->mlx, file, &width, &height);
	}
	if (!tmp)
	{
		ft_printf("%s xpm to image failed\n", target);
		return (0);
	}
	ft_set_texture(game, target, tmp);
	ft_printf("%s done\n", target);
	return (1);
}

int ft_load_elements(t_game *game, char *line)
{
	if (ft_startswith(line, "NO")) {
		if (!ft_load_texture(game, line, "NO"))
			return (0);
	} else if (ft_startswith(line, "SO")) {
		if (!ft_load_texture(game, line, "SO"))
			return (0);
	} else if (ft_startswith(line, "WE")) {
		if (!ft_load_texture(game, line, "WE"))
			return (0);
	} else if (ft_startswith(line, "EA")) {
		if (!ft_load_texture(game, line, "EA"))
			return (0);
	} else if (ft_startswith(line, "F")) {
		if (!ft_load_color(game, line, 'F'))
			return (0);
	} else if (ft_startswith(line, "C")) {
		if (!ft_load_color(game, line, 'C'))
			return (0);
	}
	return (1);
}
