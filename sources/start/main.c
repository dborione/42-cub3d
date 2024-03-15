/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:30:11 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/15 18:18:11 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../../includes/cub3d_loading.h"
#include "../../includes/cub3d_listeners.h"
#include "../../includes/cub3d_render.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
	{
		ft_putendl_fd("Error.", 2);
		return (1);
	}
	if (!ft_init_game(&game))
	{
		ft_putendl_fd("Error.", 2);
		return (127);
	}
	if (!ft_load_game(game, argv[1]))
	{
		ft_putendl_fd("Error.", 2);
		return (2);
	}
	ft_set_direction_and_camera(game);
	ft_key_hook_pressed(game);
	ft_render_frame(game);
	ft_close_button_hook(game);
	mlx_loop(game->mlx);
	ft_unload_game(game);
	return (0);
}
