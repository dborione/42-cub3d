/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_loading.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:05:10 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/01/22 23:17:33 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_LOADING
# define CUB3D_LOADING
# include "cub3d.h"
# include "../libft/libft.h"

int		ft_load_game(t_game *game, char *map_path);
int 	ft_load_elements(t_game *game, char *line);
int		ft_load_color(t_game *game, char *line, char target);
void	ft_unload_textures(t_game *game);

#endif