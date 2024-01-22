/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:43:54 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/01/22 14:20:09 by rbarbiot         ###   ########.fr       */
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

t_rgb	*ft_load_color(char *line)
{
	int		i;
	char	**brut_rgb;

	if (!line[1])
		return (NULL);
	i = 2;
	while (ft_isspace(line[i]))
		i++;
	if (!line[i])
		return (NULL);
	brut_rgb = ft_split(&line[i], ',');
	if (!brut_rgb)
		return (NULL);
	if (ft_split_len(brut_rgb) != 3)
	{
		ft_free_split(brut_rgb);
		return (NULL);
	}
	return (ft_get_rgb(brut_rgb));
}
