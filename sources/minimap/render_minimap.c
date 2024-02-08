/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:41:55 by dborione          #+#    #+#             */
/*   Updated: 2024/02/08 11:41:57 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/cub3d_render.h"
#include "../includes/cub3d_listeners.h"
#include <stdio.h> // a enlever

#define WHITE 0xFFFFFF
#define BLUE 0x000000FF
#define RED 0x00FF0000
#define GREEN 0x0000FF00

void    ft_get_map_size(t_game *game)
{
    int i;
    int j;
    int map_height;

    i = -1;
    j = -1;
    int map_width = 0;
	while (game->textures->map[++i])
    {
        while (game->textures->map[i][++j]) {};
        if (j > map_width)
            map_width = j;
        j = -1;
    }
    map_height = i * TILE_SIZE;
    map_width *= TILE_SIZE;
    game->minimap_img_ptr = mlx_new_image(game->mlx, map_width, map_height);

}

void    ft_draw_borders(t_game *game, int i, int j, int color)
{
    for (int x = 0; x < TILE_SIZE; x++)
    {
        mlx_pixel_put(game->mlx, game->mlx_win, 100 + (j * TILE_SIZE) + x, 100 + (i * TILE_SIZE), color);
        mlx_pixel_put(game->mlx, game->mlx_win, 100 + (j * TILE_SIZE), 100 + (i * TILE_SIZE) + x, color);
        mlx_pixel_put(game->mlx, game->mlx_win, (100 + TILE_SIZE) + (j * TILE_SIZE), 100 + (i * TILE_SIZE) + x, color);
        mlx_pixel_put(game->mlx, game->mlx_win, 100 + (j * TILE_SIZE) + x, (100 + TILE_SIZE) + (i * TILE_SIZE), color);
    }
}


// int	ft_check_move(t_game *game, int pos_x, int pos_y)
// {
// 	if (game->textures->map[pos_x][pos_y] == '1')
// 		return (0);
// 	ft_init_map(game);
// 	return (1);
// }

// int	ft_minimap_key_hook(int keycode, t_game *game)
// {
//     if (keycode == W_KEY || keycode == UP_ARROW_KEY)
//         return (ft_check_move(game, game->start->x - 1, game->start->y));
//     if (keycode == S_KEY || keycode == DOWN_ARROW_KEY)
//         return (ft_check_move(game, game->start->x + 1, game->start->y));
//     if (keycode == D_KEY || keycode == RIGHT_ARROW_KEY)
//         return (ft_check_move(game, game->start->x, game->start->y + 1));
//     if (keycode == A_KEY || keycode == LEFT_ARROW_KEY)
//         return (ft_check_move(game, game->start->x, game->start->y - 1));
//     return (1);
// }

int	ft_render_minimap(t_game *game)
{
    int i;
    int j;

    ft_get_map_size(game);
    i = -1;
    j = -1;
	game->minimap = mlx_put_image_to_window(game->mlx, game->mlx_win, game->minimap_img_ptr, 100, 100);
    while (game->textures->map[++i])
    {
        while (game->textures->map[i][++j])
        {
            if (game->textures->map[i][j] == '1')
                ft_draw_borders(game, i, j, BLUE);
            if (game->textures->map[i][j] == 'N')
            {
                for (int x = 0; x < TILE_SIZE; x++)
                    mlx_pixel_put(game->mlx, game->mlx_win, 100 + (game->start->x * TILE_SIZE)
                        + (TILE_SIZE/2), 100 + ((game->start->y - 1)* TILE_SIZE) + x, GREEN);
            }

        }
        j = -1;
    }
    // regler la position de la minimap plus tard
    ft_draw_borders(game, game->start->y, game->start->x, WHITE);
    // mlx_key_hook(game->mlx_win, ft_minimap_key_hook, game);
    return (1);
}


