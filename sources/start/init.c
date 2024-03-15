/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:26:43 by dborione          #+#    #+#             */
/*   Updated: 2024/03/14 12:26:45 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_init_game(t_game **game)
{
	*game = malloc(sizeof(t_game));
	if (!*game)
		return (0);
	(*game)->mlx = mlx_init();
	if (!(*game)->mlx)
	{
		free(*game);
		return (0);
	}
	(*game)->mlx_win = mlx_new_window((*game)->mlx,
			WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	(*game)->textures = NULL;
	(*game)->player = NULL;
	(*game)->rotate_left = 0;
	(*game)->rotate_right = 0;
	(*game)->player_dir_y = 0;
	(*game)->player_dir_x = 0;
	(*game)->camera_plane_x = 0;
	(*game)->camera_plane_y = 0;
	return (1);
}
