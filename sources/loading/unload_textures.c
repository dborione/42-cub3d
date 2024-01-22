/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unload_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:38:48 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/01/22 14:41:40 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include <stdlib.h>

void	ft_unload_textures(t_game *game)
{
	if (!game->textures)
		return ;
	if (game->textures->ceiling)
		free(game->textures->ceiling);
	if (game->textures->floor)
		free(game->textures->floor);
	if (game->textures->map)
		ft_free_split(game->textures->map);
}