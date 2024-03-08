/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycasting.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:41:55 by dborione          #+#    #+#             */
/*   Updated: 2024/03/08 09:49:19 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAYCASTING
# define CUB3D_RAYCASTING
# include "cub3d.h"
# include "../libft/libft.h"

# include <math.h>
# include <limits.h>

# define FOV 0.70;

typedef struct s_line
{
    float   wall_hit_x;
    int     height;
    int     bottom; //start
    int     top; //end
    int     texture_x;
    int     texture_y;
    float   texture_pos;
    float   texture_map_pos;
    float   step;
    int     text_num;
}   t_line;

typedef struct s_ray
{
    float   camera_pos_x; // la position du ray sur la plane de caméra
    float   dir_x; // les vecteurs de direction x et y du ray
    float   dir_y;
    int     map_pos_x; // les positions x et y de la case de la map où le vecteur est situé
    int     map_pos_y;
	int     last_map_pos_x; // les positions x et y de la case de la map où le vecteur est situé
    int     last_map_pos_y;
    float   tile_dist_x; // la distance que le ray doit parcourir entre sa position de depart et la première pos de la map x
    float   tile_dist_y; // la distance que le ray doit parcourir entre sa position de depart et la première pos de la map y
    float   delta_dist_x; // la distance que le ray doit parcourir entre une tile_pos_x et la prochaine intersection x
    float   delta_dist_y;
    int     hit;
    int     side; // mur NS ou EW 
    int     step_x;
    int     step_y;
    float   ray_to_wall_dist;
}   t_ray;

typedef struct s_raycaster
{
    float   player_pos_x;
    float   player_pos_y;
    float   player_dir_x; // -1 pour N, 1 pour S, 0 pour E/W
    float   player_dir_y; // -1 pour W, 1 pour E, 0 pour S/N
    float   camera_plane_x; // 0.66 pour E, -0.66 pour W, 0 pour S/N
    float   camera_plane_y; // 0.66 pour N, -0.66 pour S, 0 pour E/W
	char	wall_id;
    t_ray   *ray;
    t_line  *line;
}   t_raycaster;



void        ft_dda_loop(t_game *game, t_raycaster *raycaster);
void        ft_get_wall_infos(t_game *game, t_raycaster *raycaster);
void        ft_get_texture_pos(t_raycaster *raycaster);
void        ft_draw_imgs(t_game *game, t_raycaster *raycaster, int x);

/* News */

t_raycaster *ft_new_raycaster(t_game *game);
t_ray       *ft_new_ray(void);
t_line      *ft_new_line(void);

/* Clears */

void		ft_clear_line(t_line *line);
void		ft_clear_ray(t_ray *ray);

/*
	Ils permettent d'éviter de devoir free puis init à
	chaque boucle, ils remettent toutes les valeurs
	tel qu'à l'initialisation
*/

/* Update */

void	ft_update_raycaster(t_game *game, t_raycaster *raycaster, int i);

/*
	Met à jour le rayson (utile quand on le décalle pixel par pixel)
*/

#endif