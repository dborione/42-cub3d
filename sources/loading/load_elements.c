/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:11:14 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/15 16:36:40 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/cub3d_loading.h"

/* Verifie si la texture n'a pas déjà été chargée */
static
int	ft_texture_loaded(t_game *game, char target[3])
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
int	ft_load_texture(
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
	file = ft_strtrim(&line[i], "\n");
	if (!file)
		return (0);
	if (ft_endswith(file, ".xpm"))
	{
		ft_printf("%s loading file : '%s'\n", target, file);
		tmp = mlx_xpm_file_to_image(game->mlx, file, &width, &height);
	}
	free(file);
	if (!tmp)
	{
		ft_printf("%s xpm to image failed\n", target);
		return (0);
	}
	ft_set_texture(game, target, tmp);
	return (1);
}

int	ft_load_element(t_game *game, char *line)
{
	int	result;

	if (ft_startswith(line, "NO"))
		result = ft_load_texture(game, line, "NO");
	else if (ft_startswith(line, "SO"))
		result = ft_load_texture(game, line, "SO");
	else if (ft_startswith(line, "WE"))
		result = ft_load_texture(game, line, "WE");
	else if (ft_startswith(line, "EA"))
		result = ft_load_texture(game, line, "EA");
	else if (ft_startswith(line, "F"))
		result = ft_load_color(game, line, 'F');
	else if (ft_startswith(line, "C"))
		result = ft_load_color(game, line, 'C');
	else
		result = 1;
	return (result);
}
