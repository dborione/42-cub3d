/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:43:54 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/02/06 15:22:01 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_loading.h"
#include <stdlib.h>

int	ft_get_int_rgb(t_rgb *rgb)
{
	int	int_rgb;

	int_rgb = rgb->alpha << 24;
	int_rgb = rgb->red << 16;
	int_rgb += rgb->green << 8;
	int_rgb += rgb->blue;
	return (int_rgb);
}

static
t_rgb	*ft_get_rgb(char **brut_rgb)
{
	t_rgb	*rgb;

	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		return (NULL);
	rgb->alpha = 0;
	rgb->red = ft_atoi(brut_rgb[0]);
	rgb->green = ft_atoi(brut_rgb[1]);
	rgb->blue = ft_atoi(brut_rgb[2]);
	if (rgb->red > 255 || rgb->red < 0
		|| rgb->green > 255 || rgb->green < 0
		|| rgb->blue > 255 || rgb->blue < 0)
	{
		free(rgb);
		return (NULL);
	}
	return (rgb);
}

static
int		ft_color_loaded(t_game *game, char target)
{
	if (target == 'F')
		return (game->textures->floor != NULL);
	else if (target == 'C')
		return (game->textures->ceiling != NULL);
	return (0);
}

static
int		ft_set_color(t_game *game, char **brut_rgb, char target)
{
	if (target == 'F')
	{
		game->textures->floor = ft_get_rgb(brut_rgb);
		ft_free_split(brut_rgb);
		if (game->textures->floor != NULL)
			return (1);
	}
	else if (target == 'C')
	{
		game->textures->ceiling = ft_get_rgb(brut_rgb);
		ft_free_split(brut_rgb);
		if (game->textures->ceiling != NULL)
			return (1);
	}
	return (0);
}

int		ft_load_color(t_game *game, char *line, char target)
{
	int	i;
	char	**brut_rgb;

	if (ft_color_loaded(game, target) || !line[1])
		return (0);
	i = 2;
	while (ft_isspace(line[i]))
		i++;
	if (!line[i])
		return (0);
	brut_rgb = ft_split(&line[i], ',');
	if (!brut_rgb)
		return (0);
	if (ft_split_len(brut_rgb) != 3)
	{
		ft_free_split(brut_rgb);
		return (0);
	}
	return (ft_set_color(game, brut_rgb, target));
}
