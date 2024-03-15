/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:30:16 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/15 16:42:46 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/cub3d_loading.h"

int	ft_quit_window(t_game *game)
{
	ft_unload_game(game);
	system("leaks cub3D"); //a enlever
	exit (0);
	return (0);
}
