/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_listeners.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:20:36 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/01/29 15:21:18 by rbarbiot         ###   ########.fr       */
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

int	ft_key_hook(int keycode, t_game *game);

#endif