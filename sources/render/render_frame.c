/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:12:36 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/15 18:07:03 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/cub3d_loading.h"
#include "../../includes/cub3d_render.h"

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
	if (!ft_raycasting(game))
	{
		ft_unload_game(game);
		exit(127);
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->textures->frame->pointer, 0, 0);
}
