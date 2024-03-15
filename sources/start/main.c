/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:30:11 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/15 14:43:17 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../../includes/cub3d_loading.h"
#include "../../includes/cub3d_listeners.h"
#include "../../includes/cub3d_render.h"

static
void	ft_printf_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putendl_fd(map[i], 1);
		i++;
	}
}

static
void	ft_checking_game(t_game *game)
{
	ft_putendl_fd("", 1);
	if (!game->textures)
	{
		ft_printf("[!] Textures has not been loaded\n");
		return;
	}
	if (game->textures->ceiling)
		ft_printf("\x1b[32m[ok]\x1b[0m Ceiling color loaded\n");
	else
		ft_printf("\x1b[31m[!]\x1b[0m Ceiling color not loaded\n");
	if (game->textures->floor)
		ft_printf("\x1b[32m[ok]\x1b[0m Floor color loaded\n");
	else
		ft_printf("\x1b[31m[!]\x1b[0m Floor color not loaded\n");
	if (game->textures->north_texture)
		ft_printf("\x1b[32m[ok]\x1b[0m North textures loaded\n");
	else
		ft_printf("\x1b[31m[!]\x1b[0m North textures not loaded\n");
	if (game->textures->south_texture)
		ft_printf("\x1b[32m[ok]\x1b[0m South textures loaded\n");
	else
		ft_printf("\x1b[31m[!]\x1b[0m South textures not loaded\n");
	if (game->textures->east_texture)
		ft_printf("\x1b[32m[ok]\x1b[0m East textures loaded\n");
	else
		ft_printf("\x1b[31m[!]\x1b[0m East textures not loaded\n");
	if (game->textures->west_texture)
		ft_printf("\x1b[32m[ok]\x1b[0m West textures loaded\n");
	else
		ft_printf("\x1b[31m[!]\x1b[0m West textures not loaded\n");
	if (game->textures->map)
	{
		ft_printf("\x1b[32m[ok]\x1b[0m West textures loaded\n");
		ft_printf_map(game->textures->map);
	}
	else
		ft_printf("\x1b[31m[!]\x1b[0m Map schema not loaded\n");
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
	{
		ft_putendl_fd("Error.", 2);
		return (1);
	}
	if (!ft_init_game(&game))
	{
		ft_putendl_fd("Error.", 2);
		system("leaks cub3D");
		return (127);
	}
	if (!ft_load_game(game, argv[1])) //leak
	{
		ft_putendl_fd("Error.", 2);
		system("leaks cub3D");
		return (2);
	}
	ft_set_direction_and_camera(game);
	ft_checking_game(game);
	ft_key_hook_pressed(game);
	ft_render_frame(game);
	ft_close_button_hook(game);
	mlx_loop(game->mlx);
	ft_unload_game(game);
	system("leaks cub3D");
	return (0);
}

