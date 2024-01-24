/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_textures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbiot <rbarbiot@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:26:19 by rbarbiot          #+#    #+#             */
/*   Updated: 2024/01/22 14:23:14 by rbarbiot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TEXTURES_H
# define CUB3D_TEXTURES_H

/* Défini des codes pour les zones sur la map */

# define CUB3D_OUTSIDE 32
# define CUB3D_EMPTY 48
# define CUB3D_WALL 49
# define CUB3D_SPAWN_NORTH 78
# define CUB3D_SPAWN_SOUTH 83
# define CUB3D_SPAWN_WEST 87
# define CUB3D_SPAWN_EAST 69

/* Taille de murs */

# define WALL_HEIGHT 480 // voire pour les tailles les plus opti
# define WALL_WIDTH 720 // ici j'ai mis une basse résolution en 16:9

/* Type RGB pour définir les couleurs */

typedef struct s_rgb
{
	int	red;
	int green;
	int blue;
}				t_rgb;

/* Enregistre toutes les textures nécessaire */

typedef struct	s_cub3d_textures
{
	void	*north_texture;
	void	*south_texture;
	void	*west_texture;
	void	*east_texture;
	t_rgb	*floor;
	t_rgb	*ceiling;
	char	**map;
}				t_cub3d_textures;

#endif