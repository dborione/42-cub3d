/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:51:20 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/01/21 11:28:49 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/cub3d.h"

t_cub3d_textures	*ft_new_textures(void);

static
int	ft_load_file(t_cub3d_textures *textures, char *map_path)
{
}

int	ft_load_textures(t_game *game, char *map_path)
{
	if (!ft_endswith(map_path, ".cub"))
		return (0);
	game->textures = malloc(sizeof(t_cub3d_textures));
	if (!game->textures)
		return (0);
	if (!ft_load_file(game->textures, map_path))
	{
		free(game->textures);
		return (0);
	}
	return (1);
}
