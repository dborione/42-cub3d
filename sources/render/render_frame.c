/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:12:36 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/05 14:31:06 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/cub3d_render.h"

/* TESTS */
// void	draw(t_game *game)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < WIN_HEIGHT)
// 	{
// 		x = 0;
// 		while (x < WIN_WIDTH)
// 		{
// 			game->textures->frame->data[y * WIN_WIDTH + x] = game->buf[y][x];
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->frame->pointer, 0, 0);
// }
// /* TEST */
// static
// void	reset_buf(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (++i < WIN_HEIGHT)
// 	{
// 		j = -1;
// 		while (++j < WIN_WIDTH)
// 			game->buf[i][j] = 0;
// 	}
// }
/*
	Pour le moment le rendu est encore absolument basique :
	1- generation du toit / sol 
	2- generation des murs

	On verra pour les optimisations plus tard !
*/

void	ft_render_frame(t_game *game)
{
	ft_draw_ceiling(game);
	ft_draw_floor(game);
	// ft_draw_wall(game, game->textures->north_texture);
	if (!ft_raycasting(game))
	{
		system("leaks cub3D");
		exit (2); // a fixer plus tard
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->frame->pointer, 0, 0);
	// reset_buf(game);
}
