#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include "../../includes/cub3d_raycasting.h"

/*
    Ici on prend la distance entre la plane de camera et le mur: si
    on prennait la distance player/mur, on aurait un effet fisheye 
*/
static
void	ft_get_ray_to_wall_dist(t_raycaster *raycaster)
{
	if (raycaster->ray->side == EAST_WALL || raycaster->ray->side == WEST_WALL)
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
void	ft_set_wall_height(t_raycaster *raycaster)
{
	raycaster->line->height = (int)(WIN_HEIGHT
			/ raycaster->ray->ray_to_wall_dist);
	raycaster->line->bottom = -raycaster->line->height
		/ 2 + WIN_HEIGHT / 2; //start
	if (raycaster->line->bottom < 0)
		raycaster->line->bottom = 0;
	raycaster->line->top = raycaster->line->height
		/ 2 + WIN_HEIGHT / 2; //end
	if (raycaster->line->top >= WIN_HEIGHT)
		raycaster->line->top = WIN_HEIGHT - 1;
}

/*
    On calcule le point exact où le mur est hit: la coordonnee x sur la texture
*/
static
void	ft_get_wall_hit_point(t_game *game, t_raycaster *raycaster)
{
	raycaster->line->texture_map_pos
		= game->textures->map[(int)raycaster->player_pos_y]
	[(int)raycaster->player_pos_x] - 1;
	raycaster->line->wall_hit_x = 0;
	if (raycaster->ray->side == EAST_WALL
		|| raycaster->ray->side == WEST_WALL) // if side == EAST ou WEST
		raycaster->line->wall_hit_x = raycaster->player_pos_y
			+ raycaster->ray->ray_to_wall_dist * raycaster->ray->dir_y;
	else
		raycaster->line->wall_hit_x = raycaster->player_pos_x
			+ raycaster->ray->ray_to_wall_dist * raycaster->ray->dir_x;
	raycaster->line->wall_hit_x -= floor(raycaster->line->wall_hit_x);
}

void	ft_get_wall_infos(t_game *game, t_raycaster *raycaster)
{
	ft_get_ray_to_wall_dist(raycaster);
	ft_set_wall_height(raycaster);
	ft_get_wall_hit_point(game, raycaster);
}
