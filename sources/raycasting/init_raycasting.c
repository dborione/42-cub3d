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

static
float    ft_set_player_dir_x(t_game *game, t_raycaster *raycaster)
{
    if (game->player->yaw == 0.0f) //NORTH
        raycaster->player_dir_x = -1;
    else if (game->player->yaw == 180.0f) //SOUTH
        raycaster->player_dir_x = 1;
    else if (game->player->yaw == -90.0f || game->player->yaw == 90.0f) //WEST/EAST
        raycaster->player_dir_x = 0;
    return (raycaster->player_dir_x);
}

static
float   ft_set_player_dir_y(t_game *game, t_raycaster *raycaster)
{
    if (game->player->yaw == -90.0f) //WEST
        raycaster->player_dir_y = -1;
    else if (game->player->yaw == 90.0f) //EAST
        raycaster->player_dir_y = 1;
    else if (game->player->yaw == 0.0f || game->player->yaw == 180.0f) //NORTH/SOUTH
        raycaster->player_dir_y = 0;
    return (raycaster->player_dir_y);
}

static
float    ft_set_camera_plane_x(t_game *game, t_raycaster *raycaster)
{
    if (game->player->yaw == -90.0f) //WEST
        raycaster->camera_plane_x = -0.70;
    else if (game->player->yaw == 90.0f) //EAST
        raycaster->camera_plane_x = 0.70;
    else if (game->player->yaw == 0.0f || game->player->yaw == 180.0f) //NORTH/SOUTH
        raycaster->camera_plane_x = 0;
    return (raycaster->camera_plane_x);
}

static
float    ft_set_camera_plane_y(t_game *game, t_raycaster *raycaster)
{
    if (game->player->yaw == 0.0f) //NORTH
        raycaster->camera_plane_y = 0.70;
    else if (game->player->yaw == 180.0f) //SOUTH
        raycaster->camera_plane_y = -0.70;
    else if (game->player->yaw == -90.0f || game->player->yaw == 90.0f) //WEST/EAST
        raycaster->camera_plane_y = 0;
    return (raycaster->camera_plane_y);
}


// FOV = ratio between the length of the direction vector, and the length of the plane.
t_raycaster   *ft_init_raycaster(t_game *game, t_raycaster *raycaster)
{
    raycaster = malloc(sizeof(t_raycaster));
    if (!raycaster)
        return (NULL);
    raycaster->player_pos_x = game->player->x / 3;
    raycaster->player_pos_y = game->player->y / 3;
    raycaster->player_dir_x = ft_set_player_dir_x(game, raycaster);
    raycaster->player_dir_y = ft_set_player_dir_y(game, raycaster);
    raycaster->camera_plane_x = ft_set_camera_plane_x(game, raycaster);
    raycaster->camera_plane_y = ft_set_camera_plane_y(game, raycaster);
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
