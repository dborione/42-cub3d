/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:05:25 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/13 15:46:17 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RENDER
# define CUB3D_RENDER
# include "cub3d.h"
# include "cub3d_raycasting.h"

# define WHITE 0xFFFFFF
# define BLUE 0x000000FF
# define RED 0x00FF0000
# define GREEN 0x0000FF00

typedef struct s_wall_measures
{
	int	width;
	int	start;
	int	width_factor;
	int	height_factor;
	int	width_remainder;
	int	height_remainder;
	int	new_column;
	int	pixel;
	int	upper;
	int column;
}	t_wall_measures;

void	ft_draw_ceiling(t_game *game);
void	ft_draw_floor(t_game *game);
//void	ft_render_wall(t_game *game, float base_x, float base_y);
float	get_distance(float x1, float y1, float x2, float y2);
void	ft_draw_wall(t_game *game, void *target);
void 	ft_draw_vertical_line(t_game *game, t_raycaster *raycaster, int x, t_wall_measures *wall_mesures);
int	ft_render_frame(t_game *game);
//int     ft_render_minimap(t_game *game);

#endif