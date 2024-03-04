#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include "../../includes/cub3d_raycasting.h"
#include "../../includes/cub3d_render.h"


// static
// void    ft_texture_to_img(t_game *game, t_raycaster *raycaster)
// {
//     int scale;
// //     int texture_x;
// //     int texture_y;

//     scale = (raycaster->line->top * WALL_WIDTH) - (((WIN_HEIGHT * game->player->pitch) * WALL_WIDTH) / 2)
//         + ((raycaster->line->height * WALL_WIDTH) / 2);
// 	raycaster->line->texture_y = ((scale * WALL_HEIGHT) / raycaster->line->height)
// 		/ WALL_WIDTH;
    
	// game->textures->data[line->y * root->mlx_img->line_length + line->x
	// 	* root->mlx_img->bits_per_pixel / 8] = texture->data[line->tex_y
	// 	* texture->line_length + line->tex_x * (texture->bits_per_pixel / 8)];
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




// void    ft_get_texture_pos(t_raycaster *raycaster)
// {
//     raycaster->line->texture_x = (int)(raycaster->line->wall_hit_x * WALL_WIDTH);
//     if (raycaster->ray->side == EW && raycaster->ray->dir_x > 0)
//         raycaster->line->texture_x = WALL_WIDTH - raycaster->line->texture_x - 1;
//     if (raycaster->ray->side == NS && raycaster->ray->dir_x < 0)
//         raycaster->line->texture_x = WALL_WIDTH - raycaster->line->texture_x - 1;  
//     raycaster->line->step = 1.0 * WALL_HEIGHT / raycaster->line->height;
//     raycaster->line->texture_pos = (raycaster->line->bottom - WIN_HEIGHT / 2 + raycaster->line->height / 2)
//         * raycaster->line->step;

//     if (raycaster->ray->side == EW && raycaster->ray->dir_x < 0)
// 		raycaster->line->text_num = 0;
// 	else if (raycaster->ray->side == EW && raycaster->ray->dir_x >= 0)
// 		raycaster->line->text_num = 1;
// 	else if (raycaster->ray->side == NS && raycaster->ray->dir_y < 0)
// 		raycaster->line->text_num = 2;
// 	else if (raycaster->ray->side == NS && raycaster->ray->dir_y >= 0)
// 		raycaster->line->text_num = 3;
// }

// void    ft_draw_imgs(t_game *game, t_raycaster *raycaster, int x)
// {
//     int y;
//     int color;

//     color = BLUE;
//     y = raycaster->line->bottom;
//     while (y++ < raycaster->line->top)
//     {
//         raycaster->line->texture_y = (int)raycaster->line->texture_pos & (WALL_HEIGHT - 1);
//         raycaster->line->texture_pos += raycaster->line->step;
//         // game->textures->frame->data[i * WALL_WIDTH + j] = BLUE;
//         // color = game->textures[(int)raycaster->line->texture_map_pos][WALL_HEIGHT
//         //     * raycaster->line->texture_y + raycaster->line->texture_x];

//         // color = game->textures[raycaster->line->text_num].frame->data[WALL_HEIGHT
//         //     * raycaster->line->texture_y + raycaster->line->texture_x];
// 		if (raycaster->ray->side == NS)
// 			color = (color >> 1) & 8355711;
// 		game->buf[y][x] = color;
//     }
// }

/* TESTS */
void verLine(t_game *game, int x, int drawStart, int drawEnd, int color)
{
	while (drawStart < drawEnd)
	{
        mlx_pixel_put(game->mlx, game->mlx_win, x, drawStart, color);
		drawStart++;
	}
}

 /* TESTS */
void    ft_draw_test_line(t_game *game, t_raycaster *raycaster, int i)
{
    int	color;

    if (game->textures->map[raycaster->ray->map_pos_y][raycaster->ray->map_pos_y] == '1')
        color = BLUE;
    
    if (raycaster->ray->side == EW && raycaster->ray->dir_x < 0)
        color = BLUE;
    else if (raycaster->ray->side == EW && raycaster->ray->dir_x <= 0)
        color = color / 2;
    else if (raycaster->ray->side == NS && raycaster->ray->dir_y < 0)
        color = color / 2;
    else if (raycaster->ray->side == NS && raycaster->ray->dir_y <= 0)
        color = color / 2;

    verLine(game, i, raycaster->line->bottom, raycaster->line->top, color);
}

