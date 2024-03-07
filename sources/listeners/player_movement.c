/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:31 by dborione          #+#    #+#             */
/*   Updated: 2024/03/07 15:14:32 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/cub3d_render.h"
#include "../includes/cub3d_listeners.h"

static
void    ft_move_north(t_game *game, int keycode)
{
    if (keycode == W_KEY &&
        game->textures->map[(int)(game->player->y - 0.2)][(int)game->player->x] == '0')
            game->player->y -= 0.2;
    else if (keycode == S_KEY &&
        game->textures->map[(int)(game->player->y + 0.2)][(int)game->player->x] == '0')
        game->player->y += 0.2;
    else if (keycode == A_KEY &&
        game->textures->map[(int)game->player->y][(int)(game->player->x - 0.2)] == '0')
        game->player->x -= 0.2;
    else if (keycode == D_KEY &&
        game->textures->map[(int)game->player->y][(int)(game->player->x + 0.2)] == '0')
        game->player->x += 0.2;
}

static
void    ft_move_south(t_game *game, int keycode)
{
    if (keycode == W_KEY &&
        game->textures->map[(int)(game->player->y + 0.2)][(int)game->player->x] == '0')
        game->player->y += 0.2;
    else if (keycode == S_KEY &&
        game->textures->map[(int)(game->player->y - 0.2)][(int)game->player->x] == '0')
        game->player->y -= 0.2;
    else if (keycode == A_KEY &&
        game->textures->map[(int)game->player->y][(int)(game->player->x + 0.2)] == '0')
        game->player->x += 0.2;
    else if (keycode == D_KEY &&
        game->textures->map[(int)game->player->y][(int)(game->player->x - 0.2)] == '0')
        game->player->x -= 0.2;
}

static
void    ft_move_west(t_game *game, int keycode)
{
    if (keycode == W_KEY &&
        game->textures->map[(int)game->player->y][(int)(game->player->x - 0.2)] == '0')
        game->player->x -= 0.2;
    else if (keycode == S_KEY &&
        game->textures->map[(int)game->player->y][(int)(game->player->x + 0.2)] == '0')
        game->player->x += 0.2;
    else if (keycode == A_KEY &&
        game->textures->map[(int)(game->player->y + 0.2)][(int)game->player->x] == '0')
        game->player->y += 0.2;
    else if (keycode == D_KEY &&
        game->textures->map[(int)(game->player->y - 0.2)][(int)game->player->x] == '0')
        game->player->y -= 0.2;
}

static
void    ft_move_east(t_game *game, int keycode)
{
    if (keycode == W_KEY &&
        game->textures->map[(int)game->player->y][(int)(game->player->x + 0.2)] == '0')
        game->player->x += 0.2;
    else if (keycode == S_KEY &&
        game->textures->map[(int)game->player->y][(int)(game->player->x - 0.2)] == '0')
        game->player->x -= 0.2;
    else if (keycode == A_KEY &&
        game->textures->map[(int)(game->player->y - 0.2)][(int)game->player->x] == '0')
        game->player->y -= 0.2;
    else if (keycode == D_KEY &&
        game->textures->map[(int)(game->player->y + 0.2)][(int)game->player->x] == '0')
        game->player->y += 0.2;
}

void	ft_player_movement(t_game *game, int keycode)
{
	if (game->player->yaw == YAW_NORTH)
        ft_move_north(game, keycode);
	if (game->player->yaw == YAW_SOUTH)
        ft_move_south(game, keycode);
	if (game->player->yaw == YAW_WEST)
        ft_move_west(game, keycode);
	if (game->player->yaw == YAW_EAST)
        ft_move_east(game, keycode);
    // printf("x: %f, y: %f\n", game->player->x, game->player->y);
	ft_render_frame(game);
}
