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
        }
        j = -1;
    }
    // regler la position de la minimap plus tard
    ft_draw_borders(game, game->start->y, game->start->x, WHITE);
    return (1);

}
