#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include "../../includes/cub3d_raycasting.h"
#include <math.h>

static
int ft_init_ray(t_raycaster *raycaster)
{
    raycaster->ray = malloc(sizeof(t_ray));
    if (!raycaster->ray)
        return (0);
    raycaster->ray->dir_x = 0;
    raycaster->ray->dir_y = 0;
    raycaster->ray->camera_pos_x = 0;
    raycaster->ray->map_pos_x = 0;
    raycaster->ray->map_pos_y = 0;
    raycaster->ray->tile_dist_x = 0;
    raycaster->ray->tile_dist_y = 0;
    raycaster->ray->delta_dist_x = 0;
    raycaster->ray->delta_dist_y = 0;
    raycaster->ray->hit = 0;
    raycaster->ray->side = 0;
    raycaster->ray->step_x = 0;
    raycaster->ray->step_y = 0;
    raycaster->ray->ray_to_wall_dist = 0;
    return (1);
}

// FOV = ratio between the length of the direction vector, and the length of the plane.
static
int ft_init_raycaster(t_game *game, t_raycaster *raycaster)
{
    raycaster = malloc(sizeof(t_raycaster));
    if (!raycaster)
        return (0);
    raycaster->player_pos_x = game->player->x;
    raycaster->player_pos_y = game->player->y;
    raycaster->player_dir_x = -1;
    raycaster->player_dir_y = 0;
    raycaster->camera_plane_x = 0;
    raycaster->camera_plane_y = FOV;
    return (1);
}

int ft_init_raycasting(t_game *game, t_raycaster *raycaster)
{
    if (!ft_init_raycaster(game, raycaster))
        return (0);
    if (!ft_init_ray(raycaster))
    {
        free (raycaster);
        return (0);
    }
    return (1);
}