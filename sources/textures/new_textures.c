/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:23:18 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/01/22 14:19:59 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_textures.h"
#include <stdlib.h>

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