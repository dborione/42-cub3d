/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:12:36 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/02/06 15:25:38 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/cub3d_render.h"

/*
	Pour le moment le rendu est encore absolument basique :
	1- generation du toit / sol 
	2- generation des murs

	On verra pour les optimisations plus tard !
*/

void	ft_render_frame(t_game *game)
{
	t_cub3d_images	frame;

	frame.data = mlx_get_data_addr(game->textures->frame,
		&frame.bits_per_pixel, &frame.size_line, &frame.endian);
	ft_draw_ceiling(game, &frame);
	ft_draw_floor(game, &frame);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->frame, 0, 0);
}
