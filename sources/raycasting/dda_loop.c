#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include "../../includes/cub3d_raycasting.h"

static
void    ft_init_dda(t_raycaster *raycaster)
{
    // printf("line bottom: %d\n", raycaster->line->bottom);
    // printf("line bottom: %d\n", raycaster->line->bottom);
    if (raycaster->ray->dir_x < 0)
    {
        raycaster->ray->step_x = -1;
        raycaster->ray->tile_dist_x = (raycaster->player_pos_x - raycaster->ray->map_pos_x)
            * raycaster->ray->delta_dist_x;
    }
    else
    {
        raycaster->ray->step_x = 1;
        raycaster->ray->tile_dist_x = (raycaster->ray->map_pos_x + 1.0 - raycaster->player_pos_x)
            * raycaster->ray->delta_dist_x;
    }
    if (raycaster->ray->dir_y < 0)
    {
        raycaster->ray->step_y = -1;
        raycaster->ray->tile_dist_y = (raycaster->player_pos_y - raycaster->ray->map_pos_y)
            * raycaster->ray->delta_dist_y;
    }
    else
    {
        raycaster->ray->step_y = 1;
        raycaster->ray->tile_dist_y = (raycaster->ray->map_pos_y + 1.0 - raycaster->player_pos_y)
            * raycaster->ray->delta_dist_y;
    }
}

static
void    ft_do_dda(t_game *game, t_raycaster *raycaster)
{
    while (raycaster->ray->hit == 0)
    {
        if (raycaster->ray->tile_dist_x < raycaster->ray->tile_dist_y)
        {
            raycaster->ray->tile_dist_x += raycaster->ray->delta_dist_x;
            raycaster->ray->map_pos_x += raycaster->ray->step_x;
            raycaster->ray->side = 0;
        }
        else
        {
            raycaster->ray->tile_dist_y += raycaster->ray->delta_dist_y;
            raycaster->ray->map_pos_y += raycaster->ray->step_y;
            raycaster->ray->side = 1;
        }
        if (game->textures->map[raycaster->ray->map_pos_y][raycaster->ray->map_pos_x] == '1')
            raycaster->ray->hit = 1;
    }
}

void    ft_dda_loop(t_game *game, t_raycaster *raycaster)
{
    raycaster->ray->map_pos_x = raycaster->player_pos_x;
    raycaster->ray->map_pos_y = raycaster->player_pos_y;
    ft_init_dda(raycaster);
    ft_do_dda(game, raycaster);
}
