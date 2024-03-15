/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_listeners.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:20:36 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/15 14:28:40 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_LISTENERS
# define CUB3D_LISTENERS
# include "cub3d.h"
# include "../libft/libft.h"

# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define G_KEY 5
# define B_KEY 11
# define W_KEY 13
# define R_KEY 15
# define T_KEY 17
# define P_KEY 35
# define M_KEY 46
# define ESC_KEY 53
# define UP_ARROW_KEY 126
# define DOWN_ARROW_KEY 125
# define LEFT_ARROW_KEY 123
# define RIGHT_ARROW_KEY 124

# define ON_KEY_DOWN 2
# define ON_KEY_UP 3
# define ON_KEY_PRESS 1L<<0
# define ON_KEY_RELEASE 1L<<1

void	ft_key_hook_pressed(t_game *game);
void	ft_close_button_hook(t_game *game);
void	ft_player_movement(t_game *game, int keycode);

#endif