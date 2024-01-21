/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:30:11 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/01/21 11:19:38 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(void)
{
	t_game	game;
	t_data	img;


	// init struct
	// parse map
		// init raycasting
	// load textures
	// movemnt
	ft_init_game(&game, &img);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(game.mlx, game.mlx_win, img.img, 0, 0);
	mlx_hook(game.mlx_win, 17, 0, ft_quit_window, &game);
	mlx_loop(game.mlx);
}

