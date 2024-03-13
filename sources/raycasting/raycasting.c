/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:41:55 by dborione          #+#    #+#             */
/*   Updated: 2024/03/13 15:46:44 by rbarbiot         ###   ########.fr       */
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

static
int	ft_same_target(t_raycaster *raycaster, t_ray *last_ray)
{
	return (raycaster->ray->map_pos_x == last_ray->map_pos_x
		&& raycaster->ray->map_pos_y == last_ray->map_pos_y);
}

/*

on calcule les facteurs par rapport a la hauter
pour gerer la largeur on cree un facteur pour le premier 

pixel = - WIDTH / 2;
factor -= pixel -> les blocks deviennent plus petit
factor += pixel -> les blocks deviennent plus grands

on doit enregistrer le sens upper ou lower
*/

int	ft_init_raycasting(
	t_game *game, t_raycaster **raycaster, t_ray **last_ray)
{
	*raycaster = ft_new_raycaster(game);
	if (!raycaster)
		return (0);
	*last_ray = ft_new_ray();
	if (!*last_ray)
	{
		free(*raycaster);
		return (0);
	}
	return (1);
}


void	ft_save_ray(t_raycaster *source, t_ray *destination)
{
	destination->map_pos_x = source->ray->map_pos_x;
	destination->map_pos_y = source->ray->map_pos_y;
}


int		ft_get_width(
	t_game *game, t_raycaster *raycaster, t_ray *last_ray, int i)
{
	int	width;
	width = 0;
	ft_update_raycaster(game, raycaster, i);
	ft_save_ray(raycaster, last_ray);
	while (i < WIN_WIDTH && ft_same_target(raycaster, last_ray))
	{
		ft_update_raycaster(game, raycaster, i);
		width++;
		i++;
	}
	return (width);
}

int ft_raycasting(t_game *game)
{
    t_raycaster		*raycaster;
	t_ray			*last_ray;
	t_wall_measures	wall_measures;
    int         i;

	if (!ft_init_raycasting(game, &raycaster, &last_ray))
		return (0);
    i = 0;
    while (i < WIN_WIDTH)
    {
		wall_measures.width = ft_get_width(game, raycaster, last_ray, i);
		wall_measures.column = 0;
		wall_measures.start = i;
		wall_measures.width_factor = wall_measures.width / WALL_WIDTH;
		wall_measures.width_remainder = wall_measures.width % WALL_WIDTH;
		wall_measures.new_column = 0;
       	while (wall_measures.width)
		{
			ft_update_raycaster(game, raycaster, i);
			ft_draw_vertical_line(game, raycaster, i, &wall_measures);
			i++;
			wall_measures.width--;
		}
    }
	free(raycaster->ray);
	free(raycaster->line);
	free(raycaster);
	free(last_ray);
    return (1);
}
