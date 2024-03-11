/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:14:31 by dborione          #+#    #+#             */
/*   Updated: 2024/03/08 10:08:42 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/cub3d_render.h"
#include "../includes/cub3d_listeners.h"

// Ajouter la protection quand on est en 0 0 ou x 0 ou 0 y
// Pour eviter qu'on parte en negatif dans la verif

static
void    ft_move_north(t_game *game, int keycode)
{
    if (keycode == W_KEY && (game->player->y - 0.2 + 0.5) >= 0 &&
        game->textures->map[(int)(game->player->y - 0.2 + 0.5)][(int)(game->player->x + 0.5)] == '0')
            game->player->y -= 0.2;
    else if (keycode == S_KEY &&  game->textures->map[(int)(game->player->y + 0.2 + 0.5)] &&
        game->textures->map[(int)(game->player->y + 0.2 + 0.5)][(int)(game->player->x + 0.5)] == '0')
        game->player->y += 0.2;
    else if (keycode == A_KEY && (game->player->x - 0.2 + 0.5) >= 0 &&
        game->textures->map[(int)(game->player->y + 0.5)][(int)(game->player->x - 0.2 + 0.5)] == '0')
        game->player->x -= 0.2;
    else if (keycode == D_KEY && game->textures->map[(int)(game->player->y + 0.2 + 0.5)] &&
        game->textures->map[(int)(game->player->y + 0.5)][(int)(game->player->x + 0.2 + 0.5)] == '0')
        game->player->x += 0.2;
}

static
void    ft_move_south(t_game *game, int keycode)
{
    if (keycode == W_KEY && game->textures->map[(int)(game->player->y + 0.2 + 0.5)] &&
        game->textures->map[(int)(game->player->y + 0.2 + 0.5)][(int)(game->player->x + 0.5)] == '0')
        game->player->y += 0.2;
    else if (keycode == S_KEY && (game->player->y - 0.2 + 0.5) >= 0 &&
        game->textures->map[(int)(game->player->y - 0.2 + 0.5)][(int)(game->player->x + 0.5)] == '0')
        game->player->y -= 0.2;
    else if (keycode == A_KEY && game->textures->map[(int)(game->player->y + 0.2 + 0.5)] &&
        game->textures->map[(int)(game->player->y + 0.5)][(int)(game->player->x + 0.2 + 0.5)] == '0')
        game->player->x += 0.2;
    else if (keycode == D_KEY && (game->player->x - 0.2 + 0.5) >= 0 &&
        game->textures->map[(int)(game->player->y + 0.5)][(int)(game->player->x - 0.2 + 0.5)] == '0')
        game->player->x -= 0.2;
}

static
void    ft_move_west(t_game *game, int keycode)
{
    if (keycode == W_KEY && (game->player->x - 0.2 + 0.5) >= 0 &&
        game->textures->map[(int)(game->player->y + 0.5)][(int)(game->player->x - 0.2 + 0.5)] == '0')
        game->player->x -= 0.2;
    else if (keycode == S_KEY &&
        game->textures->map[(int)(game->player->y + 0.5)][(int)(game->player->x + 0.2 + 0.5)] == '0')
        game->player->x += 0.2;
    else if (keycode == A_KEY && game->textures->map[(int)(game->player->y + 0.2 + 0.5)] &&
        game->textures->map[(int)(game->player->y + 0.2 + 0.5)][(int)(game->player->x + 0.5)] == '0')
        game->player->y += 0.2;
    else if (keycode == D_KEY && (game->player->y - 0.2 + 0.5) >= 0 &&
        game->textures->map[(int)(game->player->y - 0.2 + 0.5)][(int)(game->player->x + 0.5)] == '0')
        game->player->y -= 0.2;
}

static
void    ft_move_east(t_game *game, int keycode)
{
    if (keycode == W_KEY &&
        game->textures->map[(int)(game->player->y + 0.5)][(int)(game->player->x + 0.2 + 0.5)] == '0')
        game->player->x += 0.2;
    else if (keycode == S_KEY &&  (game->player->x - 0.2 + 0.5) >= 0 &&
        game->textures->map[(int)(game->player->y + 0.5)][(int)(game->player->x - 0.2 + 0.5)] == '0')
        game->player->x -= 0.2;
    else if (keycode == A_KEY && (game->player->y - 0.2 + 0.5) >= 0 &&
        game->textures->map[(int)(game->player->y - 0.2 + 0.5)][(int)(game->player->x + 0.5)] == '0')
        game->player->y -= 0.2;
    else if (keycode == D_KEY && game->textures->map[(int)(game->player->y + 0.2 + 0.5)] &&
        game->textures->map[(int)(game->player->y + 0.2 + 0.5)][(int)(game->player->x + 0.5)] == '0')
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
	ft_render_frame(game);
}
