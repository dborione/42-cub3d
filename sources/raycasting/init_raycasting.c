#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include "../../includes/cub3d_raycasting.h"

static
t_line  *ft_init_line(void)
{
    t_line  *line;

    line = malloc(sizeof(t_line));
    if (!line)
        return (NULL);
    line->bottom = 0;
    line->top = 0;
    line->height = 0;
    return (line);
}

static
t_ray   *ft_init_ray(void)
{
    t_ray   *ray;

    ray = malloc(sizeof(t_ray));
    if (!ray)
        return (NULL);
    ray->dir_x = 0;
    ray->dir_y = 0;
    ray->camera_pos_x = 0;
    ray->map_pos_x = 0;
    ray->map_pos_y = 0;
    ray->tile_dist_x = 0;
    ray->tile_dist_y = 0;
    ray->delta_dist_x = 0;
    ray->delta_dist_y = 0;
    ray->hit = 0;
    ray->side = 0;
    ray->step_x = 0;
    ray->step_y = 0;
    ray->ray_to_wall_dist = 0;
    return (ray);
}

// FOV = ratio between the length of the direction vector, and the length of the plane.
t_raycaster   *ft_init_raycaster(t_game *game, t_raycaster *raycaster)
{
    raycaster = malloc(sizeof(t_raycaster));
    if (!raycaster)
        return (NULL);
    raycaster->player_pos_x = game->player->x / 3;
    raycaster->player_pos_y = game->player->y / 3;
    raycaster->player_dir_x = -1; // voir en fonction N/S/E/W
    raycaster->player_dir_y = 0;
    raycaster->camera_plane_x = 0;
    raycaster->camera_plane_y = FOV; // voir en fonction N/S/E/W
    raycaster->ray = ft_init_ray();
    if (!raycaster->ray)
    {
        free (raycaster);
        return (NULL);
    }
    raycaster->line = ft_init_line();
    if (!raycaster->line)
    {
        free(raycaster->ray);
        free (raycaster);
        return (NULL);
    }
    return (raycaster);
}
