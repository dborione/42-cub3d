/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_loading.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:05:10 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/02/05 14:27:23 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_LOADING
# define CUB3D_LOADING
# include "cub3d.h"
# include "../libft/libft.h"

int		ft_load_game(t_game *game, char *map_path);
int 	ft_load_element(t_game *game, char *line);
int		ft_load_color(t_game *game, char *line, char target);
void	ft_load_map_schema(t_game *game, int fd);
int		ft_load_player_location(t_game *game);
void	ft_unload_game(t_game *game);
int		ft_get_int_rgb(t_rgb *rgb);

#endif