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
static
void    ft_cast_rays(t_raycaster *raycaster)
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
    // check if raycaster->ray->dir_x ou raycaster->ray->dir_y == 0 pour la division
    if (raycaster->ray->dir_x == 0)
        raycaster->ray->dir_x = INT_MAX;
    if (raycaster->ray->dir_y == 0)
        raycaster->ray->dir_y = INT_MAX;
    raycaster->ray->delta_dist_x = fabs(1 / raycaster->ray->dir_x);
    raycaster->ray->delta_dist_y = fabs(1 / raycaster->ray->dir_y);

    // printf("raycaster->ray->delta_dist_x: %f\n", raycaster->ray->delta_dist_x);
    // printf("raycaster->ray->delta_dist_y: %f\n", raycaster->ray->delta_dist_y);
}

int ft_raycasting(t_game *game)
{
    t_raycaster *raycaster;

    raycaster = NULL;
    raycaster = ft_init_raycaster(game, raycaster);
    if (!raycaster)
    {
        ft_printf("error init raycasting\n");
        return (0);
    }
    ft_cast_rays(raycaster);
    ft_dda_loop(game, raycaster);
    ft_get_wall_infos(raycaster);

    ft_get_texture_pos(raycaster);
    ft_draw_imgs(game, raycaster);

    ft_draw_test_line(game, raycaster);

    return (1);
}
