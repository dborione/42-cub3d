#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include "../../includes/cub3d_raycasting.h"

t_line  *ft_init_line(void)
{
    t_line  *line;

    line = malloc(sizeof(t_line));
    if (!line)
        return (NULL);
    line->wall_hit_x = 0;
    line->height = 0;
    line->bottom = 0;
    line->top = 0;
    line->texture_x = 0;
    line->texture_y = 0;
    line->texture_pos = 0;
    line->step = 0;
    return (line);
}

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
