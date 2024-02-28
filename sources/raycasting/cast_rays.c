#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include "../../includes/cub3d_raycasting.h"
#include <math.h>


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
    // check if raycaster->ray->dir_x ou raycaster->ray->dir_y == 0 pour la division
    raycaster->ray->delta_dist_x = sqrt(1 + (raycaster->ray->dir_y * raycaster->ray->dir_y)
        / (raycaster->ray->dir_x * raycaster->ray->dir_x));
    raycaster->ray->delta_dist_y = sqrt(1 + (raycaster->ray->dir_x * raycaster->ray->dir_x)
        / (raycaster->ray->dir_y * raycaster->ray->dir_y));

    return (1);
}

/*
    Ici on prend la distance entre la plane de camera et le mur: si
    on prennait la distance player/mur, on aurait un effet fisheye 
*/
static
void ft_get_ray_to_wall_dist(t_raycaster *raycaster)
{
    if (raycaster->ray->side == 0)
        raycaster->ray->ray_to_wall_dist = (raycaster->ray->tile_dist_x
            - raycaster->ray->delta_dist_x);
    else
        raycaster->ray->ray_to_wall_dist = (raycaster->ray->tile_dist_y
            - raycaster->ray->delta_dist_y);
}

/*
    On calcule la hauteur des murs par rapport à la distance
*/
static
void ft_set_wall_height(t_raycaster *raycaster)
{
    int wall_heigt;
    int wall_bottom;
    int wall_top;

    wall_heigt = (int)(HEIGHT / raycaster->ray->ray_to_wall_dist);
    wall_bottom = -wall_heigt / 2 + HEIGHT / 2;
    if (wall_bottom < 0)
        wall_bottom = 0;
    wall_top = wall_heigt / 2 + HEIGHT / 2;
    if (wall_top >= HEIGHT)
        wall_top = HEIGHT - 1;
}

/*
    On calcule le point exact où le mur est hit
*/
static
void    ft_get_wall_hit_point(t_raycaster *raycaster)
{
    float wall_hit;
    int texture_x;

    wall_hit = 0;
    if (raycaster->ray->side == 0) // if side == EAST ou WEST
        wall_hit = raycaster->player_pos_y +
            raycaster->ray->ray_to_wall_dist * raycaster->ray->dir_y;
    else
        wall_hit = raycaster->player_pos_x +
            raycaster->ray->ray_to_wall_dist * raycaster->ray->dir_x;
    wall_hit -= floor((double)wall_hit); // double floor(double x) = returns the largest integer value less than or equal to x

    // texture_x = (int)(wall_hit * TEXTURE_WIDTH);
    // if (raycaster->ray->side == 0 && raycaster->ray->dir_x > 0)
    //     texture_x = TEXTURE_WIDTH - texture_x - 1;
    // if (raycaster->ray->side == 1 && raycaster->ray->dir_x < 0)
    //     texture_x = TEXTURE_WIDTH - texture_x - 1;
}

int ft_raycasting(t_game *game)
{
    t_raycaster *raycaster;

    raycaster = NULL;
    if (!ft_init_raycasting(game, raycaster))
        return (0); //protect
    if (!ft_cast_rays(raycaster))
        return (0); //protect
    if (!ft_dda_loop(game, raycaster))
    {
        free (raycaster);
        return (0); //protect
    }
    ft_get_ray_to_wall_dist(raycaster);
    ft_set_wall_height(raycaster);

    if (game->textures->map[raycaster->ray->map_pos_y][raycaster->ray->map_pos_x] == '1')
        // paint_texture_line(root, ray, line, wall_x);
	
    // //reset line to start at the top pixel
    // line->y0 = 0;

    // // reset line to end at the textures beginning pixel
    // line->y1 = ray->draw_start;

    // //assumes that this function paints a solid color
    // paint_line(root, line, root->crgb); //we paint the ceiling

    // //reset line to start at the bottom pixel
    // line->y0 = WIN_HEIGHT;

    // //reset line to end at the textures end pixel
    // line->y1 = ray->draw_end;

    // //assumes that this function paints a solid color
    // paint_line(root, line, root->frgb);//we paint the floor


    return (1);
}