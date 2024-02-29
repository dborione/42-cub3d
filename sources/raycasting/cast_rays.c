#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include "../../includes/cub3d_raycasting.h"
#include <math.h>
#include <limits.h>

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
    if (raycaster->ray->dir_x == 0)
        raycaster->ray->dir_x = INT_MAX;
    if (raycaster->ray->dir_y == 0)
        raycaster->ray->dir_y = INT_MAX;

    // raycaster->ray->delta_dist_x = sqrt(1 + (raycaster->ray->dir_y * raycaster->ray->dir_y)
    //     / (raycaster->ray->dir_x * raycaster->ray->dir_x));
    // raycaster->ray->delta_dist_y = sqrt(1 + (raycaster->ray->dir_x * raycaster->ray->dir_x)
    //     / (raycaster->ray->dir_y * raycaster->ray->dir_y));
    raycaster->ray->delta_dist_x = fabs(1 / raycaster->ray->dir_x);
    raycaster->ray->delta_dist_y = fabs(1 / raycaster->ray->dir_y);

    printf("raycaster->ray->delta_dist_x: %f\n", raycaster->ray->delta_dist_x);
    printf("raycaster->ray->delta_dist_y: %f\n", raycaster->ray->delta_dist_y);

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
    // printf("ray_to_wall_dist: %f\n", raycaster->ray->ray_to_wall_dist);
    // printf("line height: %d\n", raycaster->line->height);
    // printf("line bottom: %d\n", raycaster->line->bottom);

    raycaster->line->height = (int)(HEIGHT / raycaster->ray->ray_to_wall_dist);
    raycaster->line->bottom = -raycaster->line->height / 2 + HEIGHT / 2;
    if (raycaster->line->bottom < 0)
        raycaster->line->bottom = 0;
    raycaster->line->top = raycaster->line->height / 2 + HEIGHT / 2;
    if (raycaster->line->top >= HEIGHT)
        raycaster->line->top = HEIGHT - 1;
}

/*
    On calcule le point exact où le mur est hit
*/
// static
// void    ft_get_wall_hit_point(t_raycaster *raycaster)
// {
//     float wall_hit;
//     int texture_x;

//     wall_hit = 0;
//     if (raycaster->ray->side == 0) // if side == EAST ou WEST
//         wall_hit = raycaster->player_pos_y +
//             raycaster->ray->ray_to_wall_dist * raycaster->ray->dir_y;
//     else
//         wall_hit = raycaster->player_pos_x +
//             raycaster->ray->ray_to_wall_dist * raycaster->ray->dir_x;
//     wall_hit -= floor((double)wall_hit); // double floor(double x) = returns the largest integer value less than or equal to x

//     // texture_x = (int)(wall_hit * TEXTURE_WIDTH);
//     // if (raycaster->ray->side == 0 && raycaster->ray->dir_x > 0)
//     //     texture_x = TEXTURE_WIDTH - texture_x - 1;
//     // if (raycaster->ray->side == 1 && raycaster->ray->dir_x < 0)
//     //     texture_x = TEXTURE_WIDTH - texture_x - 1;
// }


// void    ft_textures_to_img(t_game *game, t_raycaster *raycaster)
// {
//     int scale;

//     scale = (line_y * WALL_WIDTH) - (((HEIGHT * game->player->pitch) * WALL_WIDTH) / 2)
//         + ((raycaster->line->height * WALL_WIDTH) / 2);
    
// }


static
void	verLine(t_game *game, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(game->mlx, game->mlx_win, x, y, color);
		y++;
	}
}

int ft_raycasting(t_game *game)
{
    t_raycaster *raycaster;

    raycaster = NULL;
    raycaster = ft_init_raycaster(game, raycaster);
    if (!raycaster)
    {
        printf("error init raycasting\n");
        return (0); //protect
    }
    if (!ft_cast_rays(raycaster))
        return (0); //protect
    if (!ft_dda_loop(game, raycaster))
    {
        free (raycaster);
        return (0); //protect
    }
    ft_get_ray_to_wall_dist(raycaster);
    ft_set_wall_height(raycaster);

    int	color;

    if (game->textures->map[raycaster->ray->map_pos_y][raycaster->ray->map_pos_y] == '1')
        color = 0xFFFF00;
    // else if (game->textures->map[raycaster->ray->map_pos_y][raycaster->ray->map_pos_y] == 2)
    //     color = 0x00FF00;
    // else if (game->textures->map[raycaster->ray->map_pos_y][raycaster->ray->map_pos_y])
    //     color = 0x0000FF;
    // else if (game->textures->map[raycaster->ray->map_pos_y][raycaster->ray->map_pos_y])
    //     color = 0xFFFFFF;
    // else
    //     color = 0xFFFF00;
    
    if (raycaster->ray->side == 1)
        color = color / 2;
    // printf("line top: %d\n", raycaster->line->top);
    // printf("height: %d\n", HEIGHT);
    verLine(game, 50, raycaster->line->bottom, raycaster->line->top, color);

    return (1);
}