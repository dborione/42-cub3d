/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:41:55 by dborione          #+#    #+#             */
/*   Updated: 2024/03/07 15:07:55 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include "../../includes/cub3d_raycasting.h"
#include "../../includes/cub3d_render.h"

/*
    On caste des rays pour chaque pixel de la largeur de la fenêtre
    Le ray commence à la position du player
    camera_pos_x = la position x sur la plane de camera, perpendiculaire
        au vecteur de direction du player
    côté droit de l'écran = 1
    centre de l'écran = 0
    côté gauche de l'écran = -1
    donc direction du ray: addition du direction_vector et d'une partie du camera_plane vector
*/
/* Ray direction + position */

int ft_raycasting(t_game *game)
{
    t_raycaster *raycaster;
    int         i;

    raycaster = ft_new_raycaster(game);
	if (!raycaster)
		return (0);
    i = 0;
    while (i < WIN_WIDTH)
    {   
       	ft_update_raycaster(game, raycaster, i);
        ft_draw_vertical_line(game, raycaster, i);
        i++;
    }
	free(raycaster->ray);
	free(raycaster->line);
	free(raycaster);
    return (1);
}
