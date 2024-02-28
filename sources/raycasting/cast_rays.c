#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include "../../includes/cub3d_raycasting.h"
#include <math.h>



/*
    Ici on caste des rays pour chaque pixel de la largeur de la fenêtre
    Le ray commence à la position du player
    camera_pos_x = la position x sur la plane de camera, perpendiculaire
        au vecteur de direction du player
    côté droit de l'écran = 1
    centre de l'écran = 0
    côté gauche de l'écran = -1
    donc direction du ray: addition du direction_vector et d'une partie du camera_plane vector
*/
int ft_cast_rays(t_raycaster *raycaster)
{
    int     i;

    i = -1;
    while (++i < WIDTH)
    {
        raycaster->ray->camera_pos_x = 2 * i / (float)WIDTH - 1;
        raycaster->ray->dir_x = raycaster->player_dir_x + raycaster->camera_plane_x
            * raycaster->ray->camera_pos_x;
        raycaster->ray->dir_y = raycaster->player_dir_y + raycaster->camera_plane_y
            * raycaster->ray->camera_pos_x;
    }
    raycaster->ray->delta_dist_x = sqrt(1 + (raycaster->ray->dir_y * raycaster->ray->dir_y)
        / (raycaster->ray->dir_x * raycaster->ray->dir_x));
    raycaster->ray->delta_dist_y = sqrt(1 + (raycaster->ray->dir_x * raycaster->ray->dir_x)
        / (raycaster->ray->dir_y * raycaster->ray->dir_y));

    return (1);
}

int ft_raycasting(t_game *game)
{
    t_raycaster *raycaster;

    raycaster = NULL;
    if (!ft_init_raycasting(game, raycaster))
        return (0); //protect
    if (!ft_cast_rays(raycaster))
        return (0); //protect

    return (1);
}