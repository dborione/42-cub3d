/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_listeners.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:20:36 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/07 14:49:23 by rbarbiot         ###   ########.fr       */
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

// typedef struct s_keys_locks {
// 	char	key_w;
// 	char	key_a;
// 	char	key_s;
// 	char	key_d;
// 	char	key_up;
// 	char	key_left;
// 	char	key_down;
// 	char	key_right;
// }	t_keys_locks;

void	ft_key_hook_pressed(t_game *game);
void	ft_close_button_hook(t_game *game);
void	ft_player_movement(t_game *game, int keycode);

#endif