// #include "../../includes/cub3d.h"
// #include "../../libft/libft.h"
// #include "../../includes/cub3d_raycasting.h"


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