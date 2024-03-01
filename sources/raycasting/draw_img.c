#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include "../../includes/cub3d_raycasting.h"
#include "../../includes/cub3d_render.h"


// static
// void    ft_texture_to_img(t_game *game, t_raycaster *raycaster)
// {
//     int scale;
//     int texture_x;
//     int texture_y;

//     scale = (raycaster->line->top * WALL_WIDTH) - (((HEIGHT * game->player->pitch) * WALL_WIDTH) / 2)
//         + ((raycaster->line->height * WALL_WIDTH) / 2);
//     scale = line->y * raycaster->line->length
// 		- (HEIGHT * game->player->pitch) * raycaster->line->length
// 		/ 2 + raycaster->line->height * raycaster->line->length / 2;
// 	texture_y = ((scale * WALL_HEIGHT) / raycaster->line->height)
// 		/ raycaster->line->length;

    
// 	// root->mlx_img->data[line->y * root->mlx_img->line_length + line->x
// 	// 	* root->mlx_img->bits_per_pixel / 8] = texture->data[line->tex_y
// 	// 	* texture->line_length + line->tex_x * (texture->bits_per_pixel / 8)];
// 	// root->mlx_img->data[line->y * root->mlx_img->line_length + line->x
// 	// 	* (root->mlx_img->bits_per_pixel / 8) + 1] = texture->data[line->tex_y
// 	// 	* texture->line_length + line->tex_x
// 	// 	* (texture->bits_per_pixel / 8) + 1];
// 	// root->mlx_img->data[line->y * root->mlx_img->line_length + line->x
// 	// 	* (root->mlx_img->bits_per_pixel / 8) + 2] = texture->data[line->tex_y
// 	// 	* texture->line_length + line->tex_x
// 	// 	* (texture->bits_per_pixel / 8) + 2];
    
// }

// static
// void    ft_paint_texture_line(t_game *game, t_raycaster *raycaster)
// {



// }

// int ft_scale_img(t_game *game, t_raycaster *raycaster)
// {
//     if (game->textures->map[raycaster->ray->map_pos_y][raycaster->ray->map_pos_x] == '1')
//         ft_paint_texture_line(game, raycaster);
    

//     return (1);
// }




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

/* TESTS */
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

 /* TESTS */
void    ft_draw_test_line(t_game *game, t_raycaster *raycaster)
{
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
}