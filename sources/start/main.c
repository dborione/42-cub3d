/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:30:11 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/01/22 14:58:59 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../../includes/cub3d_loading.h"

int	main(int argc, char *argv[])
{
	t_game	*game;
	t_data	img;

	if (argc != 2)
	{
		ft_putendl_fd("Error.", 2);
		return (1);
	}
	// init raycasting
	if (!ft_init_game(&game, &img))
	{
		ft_putendl_fd("Error.", 2);
		return (127);
	}
	if (!ft_load_game(game, argv[1]))
	{
		// free(game); gerer les mlx init plus tot
		ft_putendl_fd("Error.", 2);
		return (2);
	}
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img.img, 0, 0);
	mlx_hook(game->mlx_win, 17, 0, ft_quit_window, &game);
	mlx_loop(game->mlx);
	ft_unload_textures(game);
	return (0);
}

