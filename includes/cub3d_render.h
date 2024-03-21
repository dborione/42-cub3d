/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:05:25 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/19 15:20:55 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RENDER_H
# define CUB3D_RENDER_H
# include "cub3d.h"
# include "cub3d_raycasting.h"

void	ft_draw_ceiling(t_game *game);
void	ft_draw_floor(t_game *game);
void	ft_draw_vertical_line(t_game *game, t_raycaster *raycaster, int x);
void	ft_render_frame(t_game *game);

#endif
