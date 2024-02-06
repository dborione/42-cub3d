/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:30:16 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/02/05 16:20:04 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/cub3d_loading.h"

int	ft_quit_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	ft_unload_game(game);
	free(game);
	system("leaks cub3D");
	exit (0);
	return (0);
}
