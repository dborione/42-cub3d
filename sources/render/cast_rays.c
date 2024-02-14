#include "../../includes/cub3d.h"
#include "../../libft/libft.h"
#include <math.h>

// projection 3d=
// (tile height / distance of player to the wall) * distance to projection
// distance of player to the wall=
// player_x_pos^2 + player_y_pos^2
// distance to projection =
// tan(tile_height / 2) * (window_width / 2)

int ft_cast_rays(t_game *game)
{
    int  x;
    int  y;

    x = game->start->x;
    y = game->start->y;
    while (game->textures->map[x][y] != '1' && game->textures->map[x + 1][y + 1] != '1'
        || game->textures->map[x - 1][y - 1] != '1')
    {
        x += cos(game->start->yaw) * M_PI / 180; //* distance between each rays; 
        y += sin(game->start->yaw) * M_PI / 180; //* distance between each rays;
        mlx_pixel_put(game->mlx, game->mlx_win, x, y, 0x00FF0000);
    }
}

int ft_move_player_fov(t_game *game)
{
    int i;

    i = -1;
    while (++i < WIDTH)
    {
        ft_cast_rays(game); 
       // 0.0333 = dividing our player angle 64 by window's witdh 1920, with it we ensure to cast every pixel in our angle
        game->start->yaw += 0.0333;
    }


}