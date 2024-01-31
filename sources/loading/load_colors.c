/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:43:54 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/01/31 19:24:58 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_loading.h"
#include <stdlib.h>

static
int	ft_get_int_rgb(t_rgb *rgb)
{
	int	int_rgb;

	int_rgb = rgb->red * 1000000;
	int_rgb += rgb->green * 1000;
	int_rgb += rgb->blue;
	return (int_rgb);
}

static
int	ft_get_rgb(char **brut_rgb)
{
	t_rgb	*rgb;
	int		int_rgb;

	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		return (0); // mettre -1 pour les erreurs
	rgb->red = ft_atoi(brut_rgb[0]);
	rgb->green = ft_atoi(brut_rgb[1]);
	rgb->blue = ft_atoi(brut_rgb[2]);
	if (rgb->red > 255 || rgb->red < 0
		|| rgb->green > 255 || rgb->green < 0
		|| rgb->blue > 255 || rgb->blue < 0)
	{
		free(rgb);
		return (0); // mettre -1 pour les erreurs
	}
	int_rgb = ft_get_int_rgb(rgb);
	free(rgb);
	ft_printf("1\n");
	return (int_rgb);
}

static
int		ft_color_loaded(t_game *game, char target)
{
	if (target == 'F')
		return (game->textures->floor != -1);
	else if (target == 'C')
		return (game->textures->ceiling != -1);
	return (0);
}

int		ft_load_color(t_game *game, char *line, char target)
{
	int		i;
	char	**brut_rgb;

	ft_printf("-4\n");
	if (ft_color_loaded(game, target) || !line[1])
		return (0);
	i = 2;
	ft_printf("-3\n");
	while (ft_isspace(line[i]))
		i++;
	if (!line[i])
		return (0);
	ft_printf("-2\n");
	brut_rgb = ft_split(&line[i], ',');
	if (!brut_rgb)
		return (0);
	ft_printf("-1\n");
	if (ft_split_len(brut_rgb) != 3)
	{
		ft_free_split(brut_rgb);
		return (0);
	}
	ft_printf("0\n");
	if (target == 'F')
		game->textures->floor = ft_get_rgb(brut_rgb);
	else if (target == 'C')
		game->textures->ceiling = ft_get_rgb(brut_rgb);
	ft_free_split(brut_rgb);
	return (1);
}
