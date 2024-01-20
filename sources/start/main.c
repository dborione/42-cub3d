/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:30:11 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/01/20 11:30:12 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(void)
{
	t_game	g;
	t_data	img;


	// init struct
	// parse map
		// init raycasting
	// load textures
	// movemnt
	ft_init_game(&g, &img);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(g.mlx, g.mlx_win, img.img, 0, 0);
	mlx_hook(g.mlx_win, 17, 0, ft_quit_window, &g);
	mlx_loop(g.mlx);
}

