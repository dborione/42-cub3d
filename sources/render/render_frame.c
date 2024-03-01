/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:12:36 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/01 13:37:04 by rbarbiot         ###   ########.fr       */
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

	game->textures->frame->data = mlx_get_data_addr(game->textures->frame->pointer,
		&(game->textures->frame)->bits_per_pixel, &(game->textures->frame)->size_line, &(game->textures->frame)->endian);
	if (!game->textures->frame->data)
		return ; // erreur de récupération de l'image
	ft_draw_ceiling(game);
	ft_draw_floor(game);
	ft_draw_wall(game, game->textures->north_texture);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures->frame->pointer, 0, 0);
}
