/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:33:41 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/07 14:46:43 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_close_button_hook(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 1L << 2, ft_quit_window, game);
}
