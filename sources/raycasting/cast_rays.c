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
    raycaster->ray->delta_dist_x = fabs(1 / raycaster->ray->dir_x);
    raycaster->ray->delta_dist_y = fabs(1 / raycaster->ray->dir_y);

    // printf("raycaster->ray->delta_dist_x: %f\n", raycaster->ray->delta_dist_x);
    // printf("raycaster->ray->delta_dist_y: %f\n", raycaster->ray->delta_dist_y);

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
    raycaster->line->bottom = -raycaster->line->height / 2 + HEIGHT / 2; //start
    if (raycaster->line->bottom < 0)
        raycaster->line->bottom = 0;
    raycaster->line->top = raycaster->line->height / 2 + HEIGHT / 2; //end
    if (raycaster->line->top >= HEIGHT)
        raycaster->line->top = HEIGHT - 1;
}

/*
    On calcule le point exact où le mur est hit: la coordonnee x sur la texture
*/
static
void    ft_get_wall_hit_point(t_raycaster *raycaster)
{
    raycaster->line->wall_hit_x = 0;
    if (raycaster->ray->side == 0) // if side == EAST ou WEST
        raycaster->line->wall_hit_x = raycaster->player_pos_y +
            raycaster->ray->ray_to_wall_dist * raycaster->ray->dir_y;
    else
        raycaster->line->wall_hit_x = raycaster->player_pos_x +
            raycaster->ray->ray_to_wall_dist * raycaster->ray->dir_x;
    raycaster->line->wall_hit_x -= floor((double)raycaster->line->wall_hit_x); // double floor(double x) = returns the largest integer value less than or equal to x
}

static
void    ft_get_texture_pos(t_raycaster *raycaster)
{
    raycaster->line->texture_x = (int)(raycaster->line->wall_hit_x * WALL_WIDTH);
    if (raycaster->ray->side == 0 && raycaster->ray->dir_x > 0)
        raycaster->line->texture_x = WALL_WIDTH + raycaster->line->texture_x;
    if (raycaster->ray->side == 1 && raycaster->ray->dir_x < 0)
        raycaster->line->texture_x = WALL_WIDTH + raycaster->line->texture_x - 1;  
    raycaster->line->step = 1.0 * WALL_HEIGHT / raycaster->line->height;
    raycaster->line->texture_pos = (raycaster->line->bottom - HEIGHT / 2 + raycaster->line->height / 2)
        * raycaster->line->step - 1;
}

static
void    ft_draw_imgs(t_game *game, t_raycaster *raycaster)
{
    int i;
    int j;

    i = raycaster->line->bottom;
    j = -1;
    while (++j < WIDTH)
    {
        while (++i <= raycaster->line->top)
        {
            raycaster->line->texture_y = (int)raycaster->line->texture_pos & (WALL_HEIGHT - 1);
            raycaster->line->texture_pos += raycaster->line->step;
            game->textures->frame->data[i * WALL_WIDTH + j] = BLUE;
            // color = game->textures[texNum][WALL_HEIGHT * texture_y + texture_x];
        }
    }

}


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
    ft_get_wall_hit_point(raycaster);
    ft_get_texture_pos(raycaster);
    ft_draw_imgs(game, raycaster);

    /* TESTS */
    int	color;

    if (game->textures->map[raycaster->ray->map_pos_y][raycaster->ray->map_pos_y] == '1')
        color = GREEN;
        // color = 0xFFFF00;
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
    verLine(game, 550, raycaster->line->bottom, raycaster->line->top, color);

    return (1);
}