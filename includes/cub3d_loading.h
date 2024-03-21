/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_loading.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:05:10 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/03/19 15:30:03 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_LOADING_H
# define CUB3D_LOADING_H
# include "cub3d.h"
# include "../libft/libft.h"

int		ft_load_game(t_game *game, char *map_path);
int		ft_load_element(t_game *game, char *line);
int		ft_load_color(t_game *game, char *line, char target);
void	ft_load_map_schema(t_game *game, int fd);
int		ft_parse_map(t_game *game);
void	ft_unload_game(t_game *game);
int		ft_add_player_location(t_game *game, size_t x, size_t y);
int		ft_is_start_location(char c);
int		ft_check_walls(t_game *game, size_t y);
int		ft_check_north_and_south_walls(t_game *game);
int		ft_has_north_wall(t_game *game);
int		ft_has_south_wall(t_game *game);
int		ft_check_corridor_walls(t_game *game, size_t y);
int		ft_corridord_has_end(t_game *game, size_t x, size_t y);
#endif
