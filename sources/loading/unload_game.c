/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unload_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:38:48 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/05 14:28:33 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include <stdlib.h>

void	ft_unload_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	if (!game->textures)
		return ;
	if (game->textures->map)
		ft_free_split(game->textures->map);
	if (game->textures->north_texture)
		mlx_destroy_image(game->mlx, game->textures->north_texture);
	if (game->textures->south_texture)
		mlx_destroy_image(game->mlx, game->textures->south_texture);
	if (game->textures->west_texture)
		mlx_destroy_image(game->mlx, game->textures->west_texture);
	if (game->textures->east_texture)
		mlx_destroy_image(game->mlx, game->textures->east_texture);
	if (game->textures->frame)
	{
		mlx_destroy_image(game->mlx, game->textures->frame->pointer);
		free(game->textures->frame);
	}
	if (game->player)
		free(game->player);
	free(game->textures->floor);
	free(game->textures->ceiling);
	free(game->textures);
	free(game);
}
