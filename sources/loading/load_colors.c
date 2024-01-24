/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:43:54 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/01/22 23:06:34 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_loading.h"
#include <stdlib.h>

static
t_rgb	*ft_get_rgb(char **brut_rgb)
{
	t_rgb	*rgb;

	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
	{
		ft_free_split(brut_rgb);
		return (NULL);
	}
	rgb->red = ft_atoi(brut_rgb[0]);
	rgb->green = ft_atoi(brut_rgb[1]);
	rgb->blue = ft_atoi(brut_rgb[2]);
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

int		ft_load_color(t_game *game, char *line, char target)
{
	int		i;
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
	if (target == 'F')
		game->textures->floor = ft_get_rgb(brut_rgb);
	else if (target == 'C')
		game->textures->ceiling = ft_get_rgb(brut_rgb);
	return (1);
}
